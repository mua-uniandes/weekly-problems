/**
    @author: c4ts0up
    @url:
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define endl "\n"

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const ll INF = 1e18+5, MOD = 1e9+7, NMAX = -1;

ll t, n, m, p;
vector <priority_queue <ll> > hijas;
set <ll> principes;

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/
    fast_io();

    cin >> t;
    while (t--) {
        cin >> n;
        hijas.resize(n+1);

        for (int i=1; i<=n; i++) {
            while (!hijas[i].empty()) hijas[i].pop();

            cin >> m;
            for (int j=0; j<m; j++) {
                cin >> p;
                hijas[i].push(-p);
            }
        }

        principes.clear();
        for (int i=1; i<=n; i++) principes.insert(-i);

        vector <ll> hijas_libres;

        // simulacion
        for (int i=1; i<=n; i++) {
            bool matrimonio = false;

            while (!hijas[i].empty()) {
                ll siguiente = hijas[i].top();

                hijas[i].pop();
                if (principes.count(siguiente)) {
                    principes.erase(siguiente);
                    matrimonio = true;
                    break;
                }
            }

            if (!matrimonio) hijas_libres.pb(i);
        }

        //
        if (!hijas_libres.empty()) {
            // siguiente principe
            if (!principes.empty()) {
                ll sig = -*(principes.rbegin());
                ll hij = hijas_libres[0];
                cout << "IMPROVE" << endl << hij << " " << sig << endl;
            }
            else cout << "OPTIMAL" << endl;
        }
        else cout << "OPTIMAL" << endl;
    }

    return 0;
}