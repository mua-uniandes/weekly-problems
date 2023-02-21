from sys import stdin, stdout

def solve(a, t):
    bst_pos = {}

    for idx, i in enumerate(a):
        if i not in bst_pos:
            bst_pos[i] = idx + 1

    pos = []
    for q in t:
        jpos = bst_pos[q]
        pos.append(str(jpos))
        for i,j in bst_pos.items():
            if j < jpos:
                bst_pos[i] += 1

        bst_pos[q] = 1

    return " ".join(pos)


def main():

    n,q = map(int, stdin.readline().split())
    a = stdin.readline().split()
    t = stdin.readline().split()
    stdout.write(solve(a,t))
main()