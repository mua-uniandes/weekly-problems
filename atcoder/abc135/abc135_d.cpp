//
//  abc135_d.cpp
//  Problems
//
//  Created by NicolasCardozo on 11/9/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long MOD = 1000000007LL;
    int n;
    char s[100005];
    long long dp[100005][13];  //reminder of 13 is j
    int i, j, ki; uint64_t res = 0;
    scanf("%s", s);
    n = strlen(s);
    dp[0][0] = 1;
    for (i = 0; i < n; i++) {
        int c;
        if (s[i] == '?') c = -1;
        else c = s[i] - '0';
        
        for (j = 0; j < 10; j++) {
            if (c != -1 && c != j) continue;
            for (ki = 0; ki < 13; ki++)
                dp[i + 1][(ki * 10 + j) % 13] += dp[i][ki];
        }
        for (j = 0; j < 13; j++) dp[i + 1][j] %= MOD;
    }
    res = dp[n][5];
    printf("%llu\n", res);
    return 0;
}

