#include<bits/stdc++.h>
#define fo(i,a,b) for (ll (i)=(a);(i)<=(b);(i)++)
#define fd(i,b,a) for (ll (i)=(b);(i)>=(a);(i)--)
#define lc (o<<1)
#define rc ((o<<1)|1)
#define mk(x,y) make_pair((x),(y))
#define eb emplace_back
#define A puts("Yes")
#define B puts("No")
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef long long i64;
const ll inf = 1ll << 60;
const ll mo1 = 1e9 + 9;
const ll mo2 = 1e9 + 7;
const ll P = 131;
const ll Q = 13331;
const int N = 2e5 + 5;
struct MCFGraph {
    struct Edge {
        int v, c, f;
        Edge(int v, int c, int f) : v(v), c(c), f(f) {}
    };
    const int n;
    std::vector<Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<i64> h, dis;
    std::vector<int> pre;
    bool dijkstra(int s, int t) {
        dis.assign(n, std::numeric_limits<i64>::max());
        pre.assign(n, -1);
        std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> que;
        dis[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            i64 d = que.top().first;
            int u = que.top().second;
            que.pop();
            if (dis[u] < d) continue;
            for (int i : g[u]) {
                int v = e[i].v;
                int c = e[i].c;
                int f = e[i].f;
                if (c > 0 && dis[v] > d + h[u] - h[v] + f) {
                    dis[v] = d + h[u] - h[v] + f;
                    pre[v] = i;
                    que.emplace(dis[v], v);
                }
            }
        }
        return dis[t] != std::numeric_limits<i64>::max();
    }
    MCFGraph(int n) : n(n), g(n) {}
    void addEdge(int u, int v, int c, int f) { // 最大流
        g[u].push_back(e.size());
        e.emplace_back(v, c, f);
        g[v].push_back(e.size());
        e.emplace_back(u, 0, -f);
    }

    std::pair<int, i64> flow(int s, int t) {
        int flow = 0;
        i64 cost = 0;
        h.assign(n, 0);
        while (dijkstra(s, t)) {
            for (int i = 0; i < n; ++i) h[i] += dis[i];
            int aug = std::numeric_limits<int>::max();
            for (int i = t; i != s; i = e[pre[i] ^ 1].v) aug = std::min(aug, e[pre[i]].c);
            for (int i = t; i != s; i = e[pre[i] ^ 1].v) {
                e[pre[i]].c -= aug;
                e[pre[i] ^ 1].c += aug;
            }
            flow += aug;
            cost += i64(aug) * h[t];
        }
        return std::make_pair(flow, cost);
    }
};
const ll INF = 1e9 + 10;
ll n, m, s, t, x, y, w, c, z;
ll mx[200][200], tot, ans[N];
int main() {

    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll s = 301, ss = 302, tt = 303, t = 304;

    cin >> n;
    fo(i, 1, n) {
        cin >> x >> y >> z;
        mx[x][y] = max(mx[x][y], z);
    }

    MCFGraph mf(305);
    fo(i, 1, 150) fo(j, 1, 150) {
        if (mx[i][j]) mf.addEdge(i, j + 150, 1, INF - mx[i][j]);
    }

    mf.addEdge(s, ss, 1, 0);
    fo(i, 1, 150) mf.addEdge(ss, i, 1, 0);
    fo(i, 151, 300) mf.addEdge(i, tt, 1, 0);
    mf.addEdge(tt, t, n, 0);

    pair<int, ll> h = make_pair(0, 0), z;
    while (1) {
        z = mf.flow(s, t);
        h.fi += z.fi;
        h.se += z.se;
        if (h.fi != tot + 1) break;
        ++tot;
        ans[tot] = tot * INF - h.se;
        mf.addEdge(s, ss, 1, 0);
    }

    cout << tot << "\n";
    fo(i, 1, tot) cout << ans[i] << "\n";

    return 0;
}
