//
//  minvote.cpp
//  Problems
//
//  Created by NicolasCardozo on 3/7/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int cases, n;
    cin >> cases;
    for(int k=0; k<cases; k++) {
        cin >> n;
        vector<long long> influence(n+10, 0);
        vector<long long> votes(n+10, 0);
        vector<long long> sum(n+10, 0);
        long long si;
        for(int j=1; j<=n; j++) {
            cin >> si;
            influence[j] = si;
            sum[j] = sum[j-1] + si;
        }
        for(int i = 1; i <= n; i++) {
            //search lower values
            int lo = 1, hi = i - 1, where = i;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if(influence[i] >= sum[i - 1] - sum[mid]) {
                    where = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            votes[where]++;
            votes[i]--;
           //search higher values
            lo = i; hi = n; where = i + 1;
            while(lo <= hi) {
                int mid = (lo + hi) / 2;
                if (influence[i] >= sum[mid - 1] - sum[i]) {
                    where = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            votes[i + 1]++;
            votes[where + 1]--;
        }
        int total = 0;
        vector<int> ans;
        for(int i = 1; i <= n; i++) {
            total += votes[i];
            ans.push_back(total);
        }
        for(int i=0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
        
    }
    return 0;
}
