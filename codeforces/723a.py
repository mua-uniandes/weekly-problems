from sys import stdin

def main():
    f = [int(x) for x in stdin.readline().split(" ")]
    z = abs(f[1] - f[0]) + abs(f[2] - f[0])
    o = abs(f[0] - f[1]) + abs(f[2] - f[1])
    t = abs(f[0] - f[2]) + abs(f[1] - f[2])
    print(min(z, o, t))

main()