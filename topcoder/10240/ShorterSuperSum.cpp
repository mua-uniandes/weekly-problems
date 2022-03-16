#include <sstream> 
#include <queue> 
#include <set> 
#include <map> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <cmath> 
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 

using namespace std; 

class ShorterSuperSum  { 
public: 
  int calculate(int k, int n) { 
      int i,j,a[100][19],sum; 
      memset(a,0,sizeof(a)); 

      for(i=1;i<=n;i++) 
            a[0][i] = i; 

        for(i=1;i<=k;i++) { 
            sum = 0; 
            for(j=1;j<=n;j++) { 
                sum += a[i-1][j]; 
                a[i][j] = sum; 
            } 
        } 

        return a[k][n]; 
  } 
};