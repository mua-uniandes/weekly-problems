//
//  abc236_d.cpp
//  Problems
//
//  Created by NicolasCardozo on 1/02/22.
//  Copyright © 2022 NicolasCardozo. All rights reserved.
//

#include<bits/stdc++.h>

using namespace std;

int n;
int a[20][20];
vector<pair<int, int>> pairs;
bool used[20];

int calc() {
  if(pairs.size() == n){
    int ret = 0;
    for(auto p : pairs) ret ^= (a[p.first][p.second]);
    return ret;
  }
  
  int l = -1;
  for(int i = 1; i <= 2*n; i++){
    if(!used[i]){
      l = i;
      break;
    }
  }
  used[l] = true;
  int ret = 0;
  for(int i = 1; i <= 2*n; i++){
    if(!used[i]){
        pairs.push_back({l, i});
        used[i] = true;
        ret = max(ret, calc());
        pairs.pop_back();
        used[i] = false;
    }
  }
    
  used[l] = false;
  return ret;
}

int main() {
  cin >> n;
  for(int i = 1; i <= 2*n-1; i++){
    for(int j = i+1; j <= 2*n; j++){
      cin >> a[i][j];
    }
  }
  cout << calc() << endl;
  return 0;
}
