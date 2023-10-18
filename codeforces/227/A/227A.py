x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())

AB = (x2-x1, y2-y1)
BC = (x3-x2, y3-y2)

cruz =(AB[0]*BC[1]-AB[1]*BC[0])
b = (AB[0]**2+AB[1]**2)**0.5 * (BC[0]**2+BC[1]**2)**0.5

if AB[1]*BC[0] == BC[1]*AB[0]:
    print("TOWARDS")
elif round(cruz/b, 2)==1:
    print("LEFT")
else:
    print("RIGHT")