/**
    @author: c4ts0up
    @language: C++
    @task: 2022-10 - MUA 7B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pb push_back
#define ff first
#define ss second
#define endl "\n"

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const ll MOD = 1e9+7, NMAX = 45, INF = 1e10;

class BadNeighbors {
    public:
        int n;
        vector <int> arr;
        int dp[NMAX][2][2];
        bool vis[NMAX][2][2];

        // empty constructor
        BadNeighbors() {}

        // principal
        int maxDonations(vector <int> sequence) {
            n = sequence.size();
            arr.resize(n);

            for (int i=0; i<n; i++) arr[i] = sequence[i];
            memset(vis, false, sizeof(vis));

            return play(0, false, false);
        }

        int play(int idx, bool prev, bool first_donated) {
            // caso base
            if (idx >= n) return 0LL;
            // caso especial último
            else if (idx == n-1 && first_donated) return 0LL;
            // caso dp
            else if (vis[idx][prev][first_donated]) return dp[idx][prev][first_donated];
            // caso recursivo
            else {
                ll take {-INF}, notake {-INF};

                // puedo tomarlo
                if (!prev) {
                    if (idx == 0) take = arr[idx] + play(idx+1, true, true);
                    else take = arr[idx] + play(idx+1, true, first_donated);
                }

                notake = play(idx+1, false, first_donated);

                vis[idx][prev][first_donated] = true;
                return dp[idx][prev][first_donated] = max(take, notake);
            }
        }
};