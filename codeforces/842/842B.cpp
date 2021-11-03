/*
ID: c4ts0up
LANG: C++
TASK: MUA 6 - B
URL: https://vjudge.net/contest/464789#problem/B
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

ld r, d;
int n;
vector <ld> x, y, rad;

ld Norma(ld xi, ld yi) {
    return sqrt(xi*xi+yi*yi);
}

bool InCrust(ld xi, ld yi, ld radi) {
    //cerr << "<" << xi << ", " << yi << ">, con un radio de " << radi << endl;

    bool fuera_centro = Norma(xi, yi) - radi >= r-d;
    bool dentro_pizza = Norma(xi, yi) + radi <= r;

    //cerr << "fuera_centro: " << fuera_centro << endl << "dentro_pizza: " << dentro_pizza << endl;

    return fuera_centro && dentro_pizza;
}

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/

    cin >> r >> d;
    cin >> n;
    x.resize(n);
    y.resize(n);
    rad.resize(n);
    for (int i=0; i<n; i++) cin >> x[i] >> y[i] >> rad[i];

    int cnt = 0;
    for (int i=0; i<n; i++) cnt += (int)(InCrust(x[i], y[i], rad[i]));
    cout << cnt << endl;
    return 0;
}