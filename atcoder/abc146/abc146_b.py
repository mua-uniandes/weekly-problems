shift = int(input())
s = input()
res=""
s = [chr(((ord(c) - 65 + shift) % 26) + 65) for c in s]
print(res.join(s))