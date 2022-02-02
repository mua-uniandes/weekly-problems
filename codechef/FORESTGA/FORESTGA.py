test = input().split(" ")
n = int(test[0])
w = int(test[1])
L = int(test[2])
heights = []
growth = []
for i in range(0,n):
    tree = input().split(" ")
    heights.append(int(tree[0]))
    growth.append(int(tree[1]))

l=0
r = 10**18+1
   
def can_cut(months):
    needed = w
    for i in range(0, len(heights)):
        h = heights[i] + growth[i]*months
        if h >= L:
            needed -= h
            if(needed <= 0):
                return True
    return False

while r - l > 1:
    mid = (l+r)//2
    if can_cut(mid):
        r = mid
    else:
        l = mid
print(r)