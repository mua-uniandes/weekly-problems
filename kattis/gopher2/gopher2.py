import sys

def main():
  line = sys.stdin.readline()
  while(line != ""): 
    n,m,s,v = [int(i) for i in line.split()]
    safety_radius_sq = (v*s)**2
    gophers = []
    escapes, hole_occupied = [], []
    for i in range(n):
      x,y = [float(j) for j in sys.stdin.readline().split()]
      gophers.append((x,y))
      escapes.append([])
    for h in range(m):
      x,y = [float(j) for j in sys.stdin.readline().split()]
      hole_occupied.append(False)
      for g in range(n):
        if ((gophers[g][0]-x)**2 + (gophers[g][1]-y)**2) <= safety_radius_sq:
          escapes[g].append(h)

    # Give priority to thoes with less options
    escape_count = [(i,len(j)) for i,j in enumerate(escapes)]
    escape_count.sort(key = lambda x:x[1])
    unsafes = 0
    for i in range(n):
      g,c = escape_count[i]
      isSafe = False
      if c>0:
        possible_escapes = escapes[g]
        for pe in possible_escapes:
          if not hole_occupied[pe]:
            hole_occupied[pe] = True
            isSafe = True
      if not isSafe:
        unsafes +=1
    print(unsafes)
    line = sys.stdin.readline()


   
if __name__ == '__main__':
  main()