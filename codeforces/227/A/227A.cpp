/**
    @author: c4ts0up
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

ll xa, ya, xb, yb, xc, yc;

struct Segmento {
    ll dx, dy;

    Segmento (ll x_1, ll y_1, ll x_2, ll y_2) {
        dx = x_2 - x_1;
        dy = y_2 - y_1;
    }

    ll mag() {
        return dx*dx + dy*dy;
    }
};


ll DotProd(Segmento s, Segmento p) {
    return s.dx * p.dx + s.dy * p.dy;
}

ll CrossProd(Segmento s, Segmento p) {
    return s.dx * p.dy - s.dy * p.dx;
}

int main() {
    #ifdef LOCAL
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    #endif
    fast_io();

    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> xc >> yc;

    Segmento s1 = Segmento(xa, ya, xb, yb);
    Segmento s2 = Segmento(xb, yb, xc, yc);

    cerr << s1.dx << " " << s1.dy << endl;
    cerr << s2.dx << " " << s2.dy << endl;
    ll crossprod = CrossProd(s1, s2);
    cerr << crossprod << endl;

    if (crossprod > 0) cout << "LEFT" << endl;
    else if (crossprod < 0) cout << "RIGHT" << endl;
    else cout << "TOWARDS" << endl;
    return 0;
}