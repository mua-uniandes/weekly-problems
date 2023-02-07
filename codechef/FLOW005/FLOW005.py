n=int(input())
for i in range(n):
    change = int(input())
    notes = [100, 50, 10, 5, 2, 1]
    count = 0
    for note in notes:
        count += change // note
        change %= note
    print(count)