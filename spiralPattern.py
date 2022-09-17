lst = [[0 for i in range(5)] for j in range(5)]
dir=True
size=4
num=1
for i in range(size):
    if(dir==True):
        for j in range(i,size):
            lst[j][i]=num
            num+=1
            
    else:
        for j in range(size-1,i-1,-1):
            lst[j][i]=num
            num+=1
    dir = not dir
for r in lst:
    for c in r:
        if c!=0:
            print(c,end=" ")
    print()