
/**
    @author: c4ts0up
    @task: MUA 2023-10 - 3A
    @url: https://vjudge.net/contest/543264#problem/B
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
#define sort(a) sort(a.begin(), a.end())

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const ll INF = 1e18 + 5, MOD = 1e9 + 7, NMAX = -1;

ll n, q;
vector <ll> posiciones;


int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/
    fast_io();

    posiciones.resize(51);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        int color;
        cin >> color;
        if (posiciones[color] == 0) posiciones[color] = i;
    }

    for (int i=0; i<q; i++) {
        int elem;
        cin >> elem;

        cout << posiciones[elem] << " ";

        for (int j=1; j<=50; j++) {
            if (posiciones[j] < posiciones[elem]) posiciones[j]++;
        }

        posiciones[elem] = 1;
    }

    cout << endl;
    return 0;
}
