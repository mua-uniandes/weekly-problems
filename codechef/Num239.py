def prettynumbers() -> str:
    t = int(input())
    resp = []
    for k in range(0, t):
        a = input().split(" ")
        l = int(a[0])
        r = int(a[1])
        x = l + (10 - l % 10)
        y = r - (r % 10)
        j = 0
        for i in range(l, x+1):
            if i % 10 == 9 or i % 10 == 2 or i % 10 == 3:
                j += 1
        for i in range(y, r+1):
            if i % 10 == 9 or i % 10 == 2 or i % 10 == 3:
                j += 1
        j += ((y - x)/10)*3
        resp.append(j)
    for i in resp:
        print(int(i))

if __name__ == '__main__':
    prettynumbers()