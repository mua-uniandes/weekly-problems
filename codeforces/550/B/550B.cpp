/**
    @author: c4ts0up
    @task: MUA 2023-10 8B
    @url: https://vjudge.net/contest/547915#problem/B
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

const ll INF = 1e18 + 5, MOD = 1e9 + 7, NMAX = -1;

ll n, l, r, x;
vll arr;

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/
    fast_io();

    cin >> n >> l >> r >> x;
    arr.resize(n);
    f(i,0,n) cin >> arr[i];

    ll res = 0;
    for (ll i=0; i<(1LL<<n); i++) {
        ll total_dif = 0, mini = INF, maxi = -INF;
        f(j,0,n) total_dif += arr[j]*((1<<j)&i ? 1LL : 0LL);
        f(j,0,n) {
            if ((1<<j)&i) mini = min(mini, arr[j]), maxi = max(maxi, arr[j]);
        }
        //cerr << "total_dif = " << total_dif << "; max = " << maxi << "; min = " << mini << " ";
        if (l <= total_dif && total_dif <= r && maxi - mini >= x) res++;
    }

    cout << res << endl;
    return 0;
}
