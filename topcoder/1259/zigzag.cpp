#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
 
using namespace std;
 
class ZigZag {
  public:
  int longestZigZag(vector <int> sequence)  {
    if(sequence.size() == 1) return 1;
    vector<int> v(sequence.size()-1);
    for(int i=1;i<sequence.size();i++) 
      v[i-1] = sequence[i] - sequence[i-1];
    int ii=0;
    while( ii < v.size() && v[ii] == 0)
    ii++;
    if(ii == v.size()) return 1;
    int dir = v[ii]; 			// dir is first nonzero
    int len = 2;
    for(int i=ii+1;i<v.size();i++)
      if(v[i] * dir < 0) {
        dir *= -1;  
        len++;
      }
    return len;
  }
};