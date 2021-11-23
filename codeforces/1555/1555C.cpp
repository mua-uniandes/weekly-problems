//
//  1555C.cpp
//  Problems
//
//  Created by NicolasCardozo on 11/9/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//


#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9 + 10;

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        vector<vector<int>> a(2, vector<int>(n));
        for(int i=0; i<2; i++)
            for(int j=0; j<n; j++)
                scanf("%d", &a[i][j]);
        int ans = INF;
        int sum1 = 0, sum2 = 0;
        for(int i=0; i<n; i++) sum1 += a[0][i];
        for(int i=0; i<n; i++){
            sum1 -= a[0][i];
            ans = min(ans, max(sum1, sum2));
            sum2 += a[1][i];
        }
        printf("%d\n", ans);
    }
}
