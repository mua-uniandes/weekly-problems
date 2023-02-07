/**
    @author: c4ts0up
    @language: C++
    @task: MUA 2023-10
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

const ll INF = 1e18+5, MOD = 1e9+7, NMAX = -1;

ll t, n, m, k;

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/

    cin >> t;
    while (t--) {
        cin >> n >> m >> k;

        ll primer_jugador = min(n/k, m);
        m -= primer_jugador;

        ll otros_jugadores = m/(k-1) + int(m % (k-1) != 0);

        cout << primer_jugador - otros_jugadores << endl;
    }
    return 0;
}