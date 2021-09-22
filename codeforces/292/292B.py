B="bus"
R="ring"
S="star"
UKN="unknown"

adj=[]
nodes, edges = map(int, input().split(" "))

for i in range(nodes):
    adj.append([])
for i in range(edges):
    a,b= map(int,input().split(" "))
    adj[a-1].append(b)
    adj[b-1].append(a)
max=0
min= 99999999999999999
count =0
for i in (range(nodes)):
    count = len(adj[i])
    if count > max:
        max=count
    if count < min :
        min= count

if max == 2 and min == 1:
    print(B, "topology")

elif max == 2 and min == 2:
    print(R, "topology")
elif max == edges and min ==1:
        print(S, "topology")
else:
    print(UKN, "topology")