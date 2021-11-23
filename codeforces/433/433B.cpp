//
//  433B.cpp
//  Problems
//
//  Created by NicolasCardozo on 11/9/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> stones(n+1);
    vector<long long> prefix(n+1);
    vector<long long> prefix_dec(n+1);
    for(int i=1; i<=n; i++) {
        long long v;
        cin >> v;
        stones[i] = v;
    }
    prefix[1] = stones[1];
    for(int i=2; i<=n; i++)
        prefix[i] = stones[i] + prefix[i-1];
    sort(stones.begin(), stones.end());
    prefix_dec[1] = stones[1];
    for(int i=2; i<=n; i++)
        prefix_dec[i] = stones[i] + prefix_dec[i-1];
    
    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        if(type == 1) {
            cout << prefix[r] - prefix[l-1] << endl;
        } else {
            cout << prefix_dec[r] - prefix_dec[l-1] << endl;
        }
    }
    return 0;
}
