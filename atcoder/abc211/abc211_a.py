from sys import stdin, stdout


line = stdin.readline().split(" ")
a = int(line[0])
b = int(line[1])

c = (a-b)/3 + b
stdout.write(str(c))