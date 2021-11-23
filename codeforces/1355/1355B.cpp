//
//  1355B.cpp
//  Problems
//
//  Created by NicolasCardozo on 11/9/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n;
        vector<long long> explorers(n);
        for(int j=0; j<n; j++) 
            cin >> explorers[j];
        sort(explorers.begin(), explorers.end());
        int groups = 0, current = 0;
        for(int j=0; j<n; j++) {
            if (++current == explorers[j]) {
                groups++;
                current = 0;
            }
        }
        cout << groups << endl;
    }
    return 0;
}
