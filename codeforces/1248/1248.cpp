/*
ID: c4ts0up
LANG: C++
TASK: MUA 3 - C - Integer Points
URL: https://vjudge.net/contest/455358#problem/C
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

const ll MOD = 1e9+7, NMAX = -1;
int t, n, m;

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/

    cin >> t;
    while (t--) {
        ll pn, in, pm, im;
        pn = in = pm = im = 0LL;

        cin >> n;
        for (int i=0; i<n; i++) {
            int aux;
            cin >> aux;
            if (aux&1) in++;
            else pn++;
        }
        cin >> m;
        for (int i=0; i<m; i++) {
            int aux;
            cin >> aux;
            if (aux&1) im++;
            else pm++;
        }

        cout << (pn*pm) + (in*im) << endl;
    }
    return 0;
}