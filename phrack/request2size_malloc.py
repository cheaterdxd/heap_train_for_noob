size_sz = 4
minsize = 8
malloc_alignment = 8
malloc_align_mask = malloc_alignment - 1
def request2size(req):
    nb = 0
    nb = req + size_sz + malloc_align_mask
    if(nb <(minsize + malloc_align_mask)):
        nb = minsize
    else:
        print('nb:'+bin(nb))
        print('~malloc_align_mask:'+bin(~malloc_align_mask))
        nb &= ~malloc_align_mask
        print('nb:'+bin(nb))
    return nb


# print( request2size(22))
# print(hex(512>>9))

def bin_index(size):
    index = 0
    tmp = size>>9
    if(tmp == 0):
        index = size>>3
    elif(tmp<=4):
        index = int(size>>6)+56 
    elif(tmp<=20):
        index = int(size>>9) + 91
    elif(tmp<=84):
        index = int(size>>12) + 110
    elif(tmp<=340):
        index = int(size>>15) + 119
    elif(tmp<=1364):
        index = int(size>>18) + 124
    else:
        index = 126
    return index

print(bin_index(16392))