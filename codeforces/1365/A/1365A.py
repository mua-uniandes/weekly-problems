n = int(input())
for i in range(n):
    board=[]
    
    n, m = map(int, input().split())
    for j in range(n):
        inp = input().split()
        board.append(inp)
        
    deleted_rows = []
    deleted_columns = []
    for j in range(n):
        for k in range(m):
            if board[j][k] == "1":
                if j not in deleted_rows:
                    deleted_rows.append(j)
                if k not in deleted_columns:
                    deleted_columns.append(k)
    m = m - len(deleted_columns)
    n = n - len(deleted_rows)

    a = min(m, n)

    if a % 2 == 0:
        print("Vivek")
    else:
        print("Ashish")