r1, c1, r2, c2 = [int(x) for x in input().split()]

# king
king = max(abs(r2-r1), abs(c2-c1))

# rook
rook = 0
# misma "file"
if (r2 == r1 or c2 == c1):
    rook = 1
else:
    rook = 2

# bishop
bishop = 0
# es de otro color
if ((r1+c1)%2 != (r2+c2)%2):
    bisohp = 0
# está en la misma diagonal
elif (r1+c1) == (r2+c2):
    bishop = 1
elif (r2-r1) == -(c2-c1):
    bishop = 1
elif (r2-r1) == (c2-c1):
    bishop = 1
else:
    bishop = 2

print(rook, bishop, king)