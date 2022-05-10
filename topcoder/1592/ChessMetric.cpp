#include <iostream> 
#include <cstdio> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <map> 
#include <cmath> 

using namespace std; 

long long ways[100][100][55]; 

const int dx[16]={1,1,1,0,-1,-1,-1,0, 2,1,-1,-2,-2,-1,1,2}; 
const int dy[16]={1,0,-1,-1,-1,0,1,1, -1,-2,-2,-1,1,2,2,1}; 

class ChessMetric { 
  public: 
  long long howMany(int size, vector <int> start, vector <int> end, int nomoves) { 
    int x,y,i,j; 
    for(x=0;x<100;x++) for(y=0;y<100;y++) for(i=0;i<55;i++) ways[y][x][i]=0; 
    int sx=start[0],sy=start[1],ex=end[0],ey=end[1]; 
    ways[sy][sx][0]=1; 
    for(i=1;i<=nomoves;i++) { 
      for(x=0;x<size;x++) 
        for(y=0;y<size;y++) { 
          for(j=0;j<16;j++) { 
            int nx=x+dx[j]; 
            int ny=y+dy[j]; 
            if (nx<0 || ny<0 || nx>=size || ny>=size) continue; 
            ways[ny][nx][i]+=ways[y][x][i-1]; 
          } 
        } 
    } 
    cout << ways[ey][ex][nomoves] << endl; 
    return ways[ey][ex][nomoves]; 
  } 
}; 