#Codigo: Camilo Rocha
from sys import stdin

M,word = None,None

def solve():
  if M==1: ans = word[0]
  else:
    word.sort()
    best,m = len(word[0]),1
    while best!=0 and m!=M:
      i,bound = 0,min(best, len(word[m]))
      while i!=bound and word[0][i]==word[m][i]: i += 1
      m,best = m+1,i
    ans = word[0][:best]
  return ans

def main():
  global M,word
  M = int(stdin.readline())
  while M!=0:
    word = [ stdin.readline().strip().lower() for _ in range(M) ]
    ans = solve()
    print(ans if len(ans)!=0 else '*')
    M = int(stdin.readline())
    
main()
