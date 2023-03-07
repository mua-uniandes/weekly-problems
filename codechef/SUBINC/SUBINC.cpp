/**
    @author: c4ts0up
    @task: MUA 2023-10 4C
    @url: https://vjudge.net/contest/545370#problem/C
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

ll t, n;
vll arr;

ll contar(ll tam) {
    return tam*(tam+1)/2LL;
}

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/
    fast_io();

    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        f(i, 0, n) cin >> arr[i];

        ll res = 0;
        ll i=0, j=-1, prev;
        while (i<n) {
            prev = -INF;
            while (j+1 < n && arr[j+1] >= prev) prev = arr[j+1], j++;
            res += contar(j-i+1);
            i=j+1;
        }

        cout << res << endl;
    }
    return 0;
}
