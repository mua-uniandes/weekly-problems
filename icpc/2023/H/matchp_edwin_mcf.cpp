#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; i++)
#define FORA(i, a, n) for(int i=a; i<n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define vd vector<double>
#define vvd vector<vd>
#define pii pair<int, int>
#define ll long long

/*MINCOST MATCHING*/
double MinCostMatching(const vvd &cost, vi &Lmate, vi &Rmate) {
    int n = int(cost.size());
    vd u(n);
    vd v(n);
    FOR(i, n) {
        u[i] = cost[i][0];
        FORA(j, 1, n) u[i] = min(u[i], cost[i][j]);
    }
    FOR(j, n) {
        v[j] = cost[0][j] - u[0];
        FORA(i, 1, n) v[j] = min(v[j], cost[i][j] - u[i]);
    }
    Lmate = vi(n, -1);
    Rmate = vi(n, -1);
    int mated = 0;
    FOR(i, n) {
        FOR(j, n) {
            if (Rmate[j] != -1) continue;
            if (fabs(cost[i][j] - u[i] - v[j]) < 1e-10) {
                Lmate[i] = j;
                Rmate[j] = i;
                mated++;
                break;
            }
        }
    }
    vd dist(n);
    vi dad(n);
    vi seen(n);
    while (mated < n) {
        int s = 0;
        while (Lmate[s] != -1) s++;
        fill(dad.begin(), dad.end(), -1);
        fill(seen.begin(), seen.end(), 0);
        FOR(k, n) dist[k] = cost[s][k] - u[s] - v[k];
        int j = 0;
        while (true) {
            j = -1;
            FOR(k, n) {
                if (seen[k]) continue;
                if (j == -1 || dist[k] < dist[j]) j = k;
            }
            seen[j] = 1;
            if (Rmate[j] == -1) break;
            const int i = Rmate[j];
            FOR(k, n) {
                if (seen[k]) continue;
                const double new_dist = dist[j] + cost[i][k] - u[i] - v[k];
                if (dist[k] > new_dist) {
                    dist[k] = new_dist;
                    dad[k] = j;
                }
            }
        }
        FOR(k, n) {
            if (k == j || !seen[k]) continue;
            const int i = Rmate[k];
            v[k] += dist[k] - dist[j];
            u[i] -= dist[k] - dist[j];
        }
        u[s] += dist[j];
        while (dad[j] >= 0) {
            const int d = dad[j];
            Rmate[j] = Rmate[d];
            Lmate[Rmate[j]] = j;
            j = d;
        }
        Rmate[j] = s;
        Lmate[s] = j;
        mated++;
    }
    double value = 0;
    FOR(i, n)
        value += cost[i][Lmate[i]];
    return value;
}
/*MINCOST MATCHING*/

int N;
vector<pii> A, B;

double dist(pii a, pii b) {
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

void solve() {
    vvd cost(N, vd(N));
    vi Lmate, Rmate;
    FOR(i, N) FOR(j, N) cost[i][j] = dist(A[i], B[j]);
    double min_cost = MinCostMatching(cost, Lmate, Rmate);
    printf("%.3lf\n", min_cost);
    //cout<<Lmate[0]+1;
    //FORA(i, 1, N) cout<<" "<<Lmate[i]+1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        cin>>N;
        if (N==0) break;
        A.resize(N);
        B.resize(N);
        FOR(i, N) cin>>A[i].first>>A[i].second;
        FOR(i, N) cin>>B[i].first>>B[i].second;
        solve();
    }
    return 0;
}