#include<bits/stdc++.h>
#define ll long long
using namespace std;

int MAX = 102;
ll dp[102][102][102];
int n,m,k;
int nums[100];
ll colors[102][102];

ll INF = 100000000000000LL;

int main(){
    scanf(" %d %d %d",&n,&m,&k);
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
    for(int i = 0; i < MAX;++i){
        for(int j = 0; j < MAX;++j){
            for(int x = 0; x < MAX;++x) dp[i][j][x] = INF;
        }
    }
    for(int i = 0; i < MAX;++i) dp[0][i][0] = 0;
    for(int i = 1; i <= n;++i){
        for(int j = 1; j <= m;++j){
            scanf(" %lld",&colors[i][j]);
        }
    }


    for(int i = 1; i <= n;++i){
        for(int j = 1; j <= m;++j){
            for(int x = 1; x <= k && (nums[i-1] == 0 || nums[i-1] == j);++x){
                dp[i][j][x] = min(dp[i][j][x],dp[i-1][j][x] + (nums[i-1] == 0? colors[i][j]:0));
                ll add = (i == 1 && x == 1? 0: INF);
                for(int ot = 1; ot <= m;++ot){
                    if(ot == j) continue;
                    add = min(dp[i-1][ot][x-1],add);
                }
                dp[i][j][x] = min(dp[i][j][x],add + (nums[i-1] == 0? colors[i][j]:0));
            }
        }
    }

    ll ans = LLONG_MAX;
    for(int i = 1; i < MAX;++i) ans = min(ans,dp[n][i][k]);

    if(ans >= INF) ans = -1;
    printf("%lld\n",ans);
    return 0;
}