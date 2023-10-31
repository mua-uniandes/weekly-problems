string = input()

cnt_v, cnt_o, total = 0,0,0
for i in range(len(string)):
    if ( string[i]== 'v'):
        if i>0 and string[i-1]=="v":
            cnt_v+=1
            total+=cnt_o
    elif string[i] == 'o':
        cnt_o+=cnt_v

print(total)
