for _ in range(int(input())):
    hc, dc = map(int, input().split())
    hm, dm = map(int, input().split())
    k, w, a = map(int, input().split())
    for i in range(k + 1):
        nhc = hc + i * a
        ndc = dc + (k - i) * w
        if (hm + ndc - 1) // ndc <= (nhc + dm - 1) // dm:
            print("YES")
            break
    else:
        print("NO")