s = "hello world"
for c in s:
    print(s)
    if(c == 'l'):
        s = s[s.index('o'):]
    print(c)
