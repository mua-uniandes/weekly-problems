
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

int n, er1, er2;
multiset <int> A, B;

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/

    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        A.insert(x);
    }

    for (int i=0; i<n-1; i++) {
        int x;
        cin >> x;
        B.insert(x);

        // lo buscamos en el otro
        A.erase(A.find(x));
    }

    er1 = *A.begin();

    for (int i=0; i<n-2; i++) {
        int x;
        cin >> x;

        // lo buscamos en B
        B.erase(B.find(x));
    }

    er2 = *B.begin();

    cout << er1 << endl << er2 << endl;
    return 0;
}