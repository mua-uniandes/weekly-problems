//
//  12783.cpp
//  Problems
//
//  Created by NicolasCardozo on 15/02/22.
//  Copyright © 2022 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

#define MAXN 10001

int N, counter, seen[MAXN], low[MAXN];
vector<int> adj[MAXN];
vector<pair<int,int>> critical ;

void dfs(int x, int parent) {
    low[x] = seen[x] = ++counter;
    for (int i = 0 ; i < adj[x].size() ; i++) {
        int y = adj[x][i];
        if (y == parent) continue;
        if (seen[y] == 0) {
            dfs(y, x);
            low[x] = min(low[x], low[y]);
            if (low[y] == seen[y])
                critical.push_back(make_pair(min(x,y),max(x,y)));
        } else {
            low[x] = min(low[x], seen[y]);
        }
    }
}

void clear() {
     for( int i = 0 ; i < N ; i++ ) {
          seen[i] = 0 ;
          adj[i].clear();
     }
     counter = 0 ;
     critical.clear();
}

int main() {
    int M;
    while( cin >> N >> M) {
        if(N==0 && M==0) return 0;

     int i, x, y;

     clear();
     for (i = 0; i < M; i++) {
             cin >> x>> y ;
             adj[x].push_back(y);
             adj[y].push_back(x);
     }
     for (x = 0; x < N; x++)
         if (seen[x] == 0) dfs(x, -1);

     printf("%lu",critical.size());
     sort(critical.begin(),critical.end());
     for( int i = 0 ; i < critical.size() ; i++ )
          printf(" %d %d", critical[i].first, critical[i].second);
      printf("\n");
     }
}
