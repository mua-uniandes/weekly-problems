s1 = input()
s2 = input()
s3 = input()
s4 = input()

s = [s1, s2, s3, s4]
for i in range (0,4):
    for j in range(0,4):
        if i!=j and s[i] == s[j]:
            print("No")
            exit()
print("Yes")