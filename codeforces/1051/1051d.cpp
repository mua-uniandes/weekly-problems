#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1000][3000][4];
ll MOD = 998244353;

ll add(ll a, ll b){
    ll ans = a + b;
    if(ans >= MOD) ans -= MOD;
    return ans;
}


int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    dp[0][1][0] = dp[0][1][3] = 1;
    dp[0][2][1] = dp[0][2][2] = 1;

    for(int i = 1; i < n;++i){
        for(int j = 1; j <= k;++j){
            //Part1
            dp[i][j][0] = add(dp[i][j][0],dp[i-1][j][0]);
            dp[i][j][0] = add(dp[i][j][0],dp[i-1][j-1][3]);
            dp[i][j][0] = add(dp[i][j][0],dp[i-1][j][1]);
            dp[i][j][0] = add(dp[i][j][0],dp[i-1][j][2]);
            //Part2
            dp[i][j][1] = add(dp[i][j][1],dp[i-1][j-1][0]);
            dp[i][j][1] = add(dp[i][j][1],dp[i-1][j-1][3]);
            dp[i][j][1] = add(dp[i][j][1],dp[i-1][j][1]);
            if(j > 1)
                dp[i][j][1] = add(dp[i][j][1],dp[i-1][j-2][2]);
            //Part3
            dp[i][j][2] = add(dp[i][j][2],dp[i-1][j-1][0]);
            dp[i][j][2] = add(dp[i][j][2],dp[i-1][j-1][3]);
            if(j > 1)
                dp[i][j][2] = add(dp[i][j][2],dp[i-1][j-2][1]);
            dp[i][j][2] = add(dp[i][j][2],dp[i-1][j][2]);
            //Part4
            dp[i][j][3] = add(dp[i][j][3],dp[i-1][j][3]);
            dp[i][j][3] = add(dp[i][j][3],dp[i-1][j-1][0]);
            dp[i][j][3] = add(dp[i][j][3],dp[i-1][j][1]);
            dp[i][j][3] = add(dp[i][j][3],dp[i-1][j][2]);
        }
    }

    ll ans = 0;
    for(int i = 0; i < 4;++i){
        ans += dp[n-1][k][i];
        if(ans >= MOD) ans -= MOD;
    }

    printf("%lld\n",ans);
    return 0;
}