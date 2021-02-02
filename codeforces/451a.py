from sys import stdin, stdout

def main():
    nums = [int(x) for x in stdin.readline().split(" ")]
    nums.sort()
    if(nums[0] % 2 == 0):
        stdout.write("Malvika\n")
    else:
        stdout.write("Akshat\n")

main()