# @author: Nicolas Cardozo
# @complexity: O(1) for each test case
# @running_time: 0.000
# @memory: 

from sys import stdin, stdout

def main():
    while(True):
        sides = stdin.readline().split(" ")
        ints = [int(x) for x in sides]
        if(ints[0]==0 and ints[1]==0 and ints[2]==0):
            break
        else:
            ints.sort()
            if(ints[0]*ints[0] + ints[1]*ints[1] == ints[2]*ints[2]):
                stdout.write("right\n")
            else:
                stdout.write("wrong\n")

main()
 