arrLen = int(input())
strArr = input().split()
arr = []
sortedArr = []
acumArr = [0]
acumSor = [0]
for x in strArr:
    arr.append(int(x))
    sortedArr.append(int(x))
    acumArr.append(0)
    acumSor.append(0)
sortedArr.sort()

for i in range(1, arrLen+1):
    acumArr[i] = acumArr[i-1] + arr[i-1]
    acumSor[i] = acumSor[i-1] + sortedArr[i-1]

numQ = int(input())

for _ in range(numQ):
    res = input().split()
    ans = 0
    selectedArr = []
    t, l, r = int(res[0]), int(res[1]), int(res[2])
    if t == 1:
        selectedArr = acumArr
    else:
        selectedArr = acumSor
    ans = selectedArr[r]-selectedArr[l-1]
    print(ans)