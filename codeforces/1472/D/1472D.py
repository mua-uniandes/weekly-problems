_ = int(input())
for __ in range(_):
    input()
    a = sorted(list(map(int, input().split())), reverse=True)
    alice = 0
    bob = 0
    for i in range(len(a)):
        if i%2==0:
            if a[i]%2==0:
                alice += a[i]
        else:
            if a[i]%2==1:
                bob += a[i]
    if alice > bob:
        print("Alice")
    elif bob > alice:
        print("Bob")
    else:
        print("Tie")

