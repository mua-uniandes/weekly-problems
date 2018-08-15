from sys import stdin, stdout

def main():
    lines = stdin.readline().split()
    a = int(lines[2])
    b = int(lines[3])
    k = int(lines[4])
    
    for i in range(1, k+1):
        query = stdin.readline().split()
        ta = int(query[0])
        fa = int(query[1])
        tb = int(query[2])
        fb = int(query[3])
        
        if (ta == tb):
            stdout.write(str(abs(fa - fb)) + "\n")
        else:    
            if (fa < a):
                stdout.write(str(a - fa + abs(ta - tb) + abs(a - fb)) + "\n")
            elif (fa > b):
                stdout.write(str(fa - b + abs(ta -tb) + abs(b - fb)) + "\n")
            else:
                stdout.write(str(abs(ta - tb) + abs(fa - fb)) + "\n")
            
main()