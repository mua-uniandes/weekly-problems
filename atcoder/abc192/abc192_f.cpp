//
//  abc192_f.cpp
//  Problems
//
//  Created by NicolasCardozo on 4/12/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;


const long long INF = 0x1fffffffffffffff;
void chmin(long long& a, long long b){ if(a > b) a = b; }
void chmax(long long& a, long long b){ if(a < b) a = b; }


int main(){
    long long N, X;
    cin >> N >> X;
    vector<long long> A(N);
    for(long long& a : A) cin >> a;
    long long ans = INF;
    for(long long k = 1; k <= N; k++){
        vector<vector<long long>> dp(k + 1, vector<long long>(k, -1));
        dp[0][0] = 0;
        for(long long a : A)
            for(long long i = k; i--; )
              for(long long j = 0; j < k; j++)
                if(dp[i][j] != -1){
                    const long long x = a + dp[i][j];
                    chmax(dp[i + 1][x % k], x);
                }
        if(dp[k][X % k] != -1)
            chmin(ans, (X - dp[k][X % k]) / k);
    }
    cout << ans << endl;
}

