/**
    @author: c4ts0up
    @task: MUA 2023-10 4E
    @url: https://vjudge.net/contest/545370#problem/E
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

priority_queue <ll> odd, even;

ll t, n;

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/
    fast_io();

    cin >> t;
    while (t--) {
        cin >> n;
        f(i, 0, n) {
            ll x;
            cin >> x;
            if (x%2 == 0) even.push(x);
            else odd.push(x);
        }

        // MOD2 = 0 : Alice
        // MOD2 = 1 : Bob
        ll alice = 0, bob = 0;
        f(i, 0, n) {
            ll mayor_par = -1;
            ll mayor_impar = -1;
            ll seleccionado;

            if (!even.empty()) mayor_par = even.top();
            if (!odd.empty()) mayor_impar = odd.top();

            if (mayor_par > mayor_impar) seleccionado = mayor_par, even.pop();
            else seleccionado = mayor_impar, odd.pop();

            if (seleccionado%2 == 0 && i%2 == 0) alice += seleccionado;
            else if (seleccionado%2 == 1 && i%2 == 1) bob += seleccionado;
        }

        if (alice == bob) cout << "Tie" << endl;
        else cout << (alice > bob ? "Alice" : "Bob") << endl;
    }

    return 0;
}
