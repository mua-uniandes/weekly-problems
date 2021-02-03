//
//  abc187_e.cpp
//  Problems
//
//  Created by NicolasCardozo on 2/1/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
 
int main(){
    ll N;
    cin >> N;
    vector<pair<ll, ll>> edge(N - 1);
    vector<vector<ll>> g(N);
    for(ll i = 0; i < N - 1; i++){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        edge[i] = {a, b};
    }
    vector<ll> depth(N, -1);
    depth[0] = 0;
    vector<ll> q = {0};
    while(q.size()){
        ll at = q.back();
        q.pop_back();
        for(ll i : g[at])
            if(depth[i] == -1){
                depth[i] = depth[at] + 1;
                q.push_back(i);
            }
    }
    vector<ll> s(N);
    ll Q;
    cin >> Q;
    while(Q--){
        ll t, e, x;
        cin >> t >> e >> x;
        auto [a, b] = edge[e - 1];
        if(depth[a] > depth[b]){
            swap(a, b);
            t ^= 3;
        }
        if(t == 1){
            s[0] += x;
            s[b] -= x;
        }
        else s[b] += x;
    }
    q = {0};
    while(q.size()){
        ll at = q.back();
        q.pop_back();
        for(ll i : g[at])
            if(depth[at] < depth[i]){
                s[i] += s[at];
                q.push_back(i);
            }
    }
    for(ll i : s) cout << i << endl;
}
