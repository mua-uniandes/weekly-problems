/**
    @author: c4ts0up
    @task: MUA 2023-10 4D
    @url: https://vjudge.net/contest/545370#problem/D
*/

#include <bits/stdc++.h>

using namespace std;

/* TIPOS */
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef set<int> si;
typedef set<ll> sll;
#define endl "\n"

/* FUNCIONES */
#define f(i, s, e) for (ll i=s; i<e; i++)
#define cf(i, s, e) for (ll i=s; i<=e; i++)
#define rf(i, e, s) for(ll i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define sort(a) sort(a.begin(), a.end())

/* PRINTS */
template<class T>
void print_v(vector<T> &v) {
    cout << "{";
    for (auto x: v) cout << x << " ";
    cout << "\b}";
}

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const ll INF = 1e18 + 5, MOD = 1e9 + 7, NMAX = 20+5, MONEY_MAX = 20*1000+5;

ll t, n, m;
vector <ll> arr;

bool dp[NMAX][MONEY_MAX];
bool vis[NMAX][MONEY_MAX];

bool Posible(ll idx, ll res) {
    // caso base
    if (idx == n) return res == 0;
    // caso base - imposible
    else if (res > 20000) return false;
    // caso dp
    else if (vis[idx][res]) return dp[idx][res];
    // caso recursivo
    else {
        bool notomar = Posible(idx+1, res);
        bool tomar = false;

        if (arr[idx] <= res) tomar = Posible(idx+1, res - arr[idx]);

        vis[idx][res] = true;
        return dp[idx][res] = tomar || notomar;
    }
}


int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/
    fast_io();

    cin >> t;
    while (t--) {
        cin >> n >> m;
        arr.resize(n);
        f(i, 0, n) cin >> arr[i];

        f(i, 0, n+1) {
            f(j, 0, m+1) dp[i][j] = vis[i][j] = false;
        }
        cout << (Posible(0, m) ? "Yes" : "No") << endl;
    }
    return 0;
}
