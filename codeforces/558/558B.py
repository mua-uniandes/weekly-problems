n = int(input())
list = list(map(lambda num: int(num), input().split(" ")))
dictionary = {}

for i in range(n):
    num = list[i]
    if num not in dictionary.keys():
        dictionary[num] = [i, i, 1]
    else:
        start, end, cnt = dictionary[num]
        dictionary[num] = [start, i, cnt + 1]

maxKey = None
max = -1
for key in dictionary.keys():
    start, end, cnt = dictionary[key]
    if cnt > max:
        maxKey = key
        max = cnt
    elif cnt == max:
        distOld = dictionary[maxKey][1] - dictionary[maxKey][0]
        distNew = end - start
        maxKey = key if distOld > distNew else maxKey

print(str(dictionary[maxKey][0] + 1) + " " + str(dictionary[maxKey][1] + 1))