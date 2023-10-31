#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
#define FOR(i, n) for(int i=0; i<n; i++)
#define FORA(i, a, n) for(int i=a; i<n; i++)
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define cost(i, j) ((i==0)?S[j]:S[j]-S[i-1])
#define INF 1000000000000LL

int N;
vll A;
vll S;

void solve() {
    vector<vll> M(N, vll(N));
    vector<vi> opt(N, vi(N));
    FOR(i, N) M[i][i] = 0;
    FOR(i, N) opt[i][i] = i;
    FORA(l, 1, N) {
        FOR(i, N-l) {
            int j = i+l;
            ll res = INF;
            FORA(k, opt[i][j-1], min(j, opt[i+1][j] + 1))
                if (res > M[i][k] + M[k+1][j]) {
                    res = M[i][k] + M[k+1][j];
                    opt[i][j] = k;
                }
            M[i][j] = res + cost(i, j);
        }
    }
    cout<<M[0][N-1]<<"\n";
}

int main() {
    fast_io;
    while(true) {
        cin>>N;
        if (N==0) break;
        A = vll(N);
        S = vll(N);
        FOR(i, N) cin>>A[i];
        S[0] = A[0];
        FORA(i, 1, N) S[i] = S[i-1] + A[i]; 
        solve();
    }
    return 0;
}