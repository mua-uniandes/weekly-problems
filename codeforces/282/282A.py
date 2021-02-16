from sys import stdin, stdout

def main():
    statements = int(stdin.readline())
    value = 0
    i = 0
    while i < statements:
        s = stdin.readline()
        if(s[0] ==  '+' or s[2] == "+"):
            value = value + 1
        else:
            value = value - 1
        i=i+1
    print(value)

main()