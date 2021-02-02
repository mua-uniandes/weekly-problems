from sys import stdin, stdout

a, b, c, d = [int(x) for x in stdin.readline().rstrip().split()]
stdout.write( str(a*b*c*d) + "\n" )