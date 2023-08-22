/**
    @author: c4ts0up
    @url: https://vjudge.net/contest/575697#problem/B
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
const ld DINF = 1e10, EPS = 1e-10;

int t, n;
string cad;

int main() {

    cin >> t;
    while (t--) {
        cin >> n;
        cin >> cad;

        int l {0}, r {0}, bi {0};
        for (char c : cad) {
            if (c == '>') r++;
            else if (c == '<') l++;
            else bi++;
        }

        // circular
        if (l == 0 || r == 0) {
            cout << n << endl;
            continue;
        }
        // hay bi
        vector <int> ret;
        ret.resize(n);
        for (int i=0; i<n; i++) ret[i] = 0;

        for (int i=0; i<n; i++) {
            if (cad[i] == '-') {
                ret[i] = 1;
                ret[(i+1)%n] = 1;
            }
        }

        int suma = 0;
        for (int x : ret) suma += x;
        cout << suma << endl;
    }

    return 0;
}