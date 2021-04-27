//
//  1029E.cpp
//  Problems
//
//  Created by NicolasCardozo on 4/24/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 2*100000;
int parent[N];
int distances[N];
vector<int> graph[N];

void dfs(int v, int pr = -1, int dst = 0) {
    distances[v] = dst;
    parent[v] = pr;
    for (auto to : graph[v]) {
        if (to != pr) {
            dfs(to, v, dst + 1);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        --x; --y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    dfs(0);
    set<pair<int, int>> st;
    for (int i = 0; i < n; ++i) {
        if (distances[i] > 2) {
            st.insert(make_pair(-distances[i], i));
        }
    }
    
    int ans = 0;
    while (!st.empty()) {
        int v = st.begin()->second;
        v = parent[v];
        ++ans;
        auto it = st.find(make_pair(-distances[v], v));
        if (it != st.end()) {
            st.erase(it);
        }
        for (auto to : graph[v]) {
            auto it = st.find(make_pair(-distances[to], to));
            if (it != st.end()) {
                st.erase(it);
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
