/**
    @author: c4ts0up
    @language: C++
    @task: CF 1777C - Quiz
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

ll t, n, s;
vector <pair <ll,ll> > arr;

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/

    cin >> s >> n;
    arr.resize(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i].ff;
        ll yi;
        cin >> yi;
        arr[i].ss = -yi;
        //cerr << arr[i].ff << "," << arr[i].ss << endl;
    }

    sort(arr.begin(), arr.end());
    bool imposible = false;

    for (pair <ll,ll> p : arr) {
        ll sdrag = p.ff;
        ll yi = -p.ss;

        //cerr << ">" << s << ", " << sdrag << " " << yi << endl;

        if (sdrag < s) s += yi;
        else imposible = true;
    }

    cout << (imposible ? "NO" : "YES") << endl;

    return 0;
}