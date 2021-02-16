from sys import stdin

def main():
    val = int(stdin.readline())
    if(val % 2 == 0):
        print(int(val/2))
    else:
        print(int(-(val+1)/2)) 

main()