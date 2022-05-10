#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define ALL(x) (x).begin(),(x).end()
typedef long long LL;
const int INF = 1000000000;
typedef vector<int> VI;
template<class T> inline int size(const T&c) { return c.size(); }
 
char buf1[1000];
 
string i2s(int x) {
  sprintf(buf1,"%d",x);
  return buf1;
}
 
 
struct FlowerGarden {
  // MAIN
  vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt) {
    int n = size(height);
    vector<bool> done(n,false);
    vector<int> res(n);
    REP(i,n) {
      int best = -1;
      REP(j,n) if(!done[j]) {
        bool ok = true;
        REP(k,n) if(k!=j && !done[k] && height[k]<height[j] &&
            bloom[k]<=wilt[j] && wilt[k]>=bloom[j]) ok = false;
        if(ok && (best==-1 || height[j]>height[best])) best=j;
      }
      res[i] = height[best];
      done[best] = true;
    }
    return res;
  }
  
 
 
};