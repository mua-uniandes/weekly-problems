s = input()
nums = input().split(" ")
a = int(nums[0])
b = int(nums[1])

println(s[0:a - 1] + s[b-1] + s[a:b - 1] + s[a-1] + s[b:len(s)])