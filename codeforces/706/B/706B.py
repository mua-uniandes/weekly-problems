def binarySearch(lst, pivot):
    lo = 0
    hi = len(lst)
    mid = 0

    while lo < hi:
        mid = (hi + lo) // 2
        if lst[mid] <= pivot:
            lo = mid + 1
        else:
            hi = mid
    return lo


n = int(input())
prices = [int(i) for i in input().split()]
prices.sort(key=int)
q = int(input())
for i in range(q):
    a = int(input())
    print(binarySearch(prices, a))