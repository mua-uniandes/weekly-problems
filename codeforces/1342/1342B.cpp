/*
ID: c4ts0up
LANG: C++
TASK: MUA 5 - A - Binary Period
URL: https://vjudge.net/contest/458894#problem/A
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
int t, n;
string cad, nueva;
char carprev;

bool Multi() {

    bool one = false, zero = false;
    for (char c : cad) {
        if (c == '1') one = true;
        else if (c == '0') zero = true;
    }

    return one && zero;
}

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/

    cin >> t;
    while (t--) {
        cin >> cad;

        if (Multi()) {
            nueva = cad[0];
            carprev = cad[0];
            n = cad.length();

            for (int i=1; i<n; i++) {
                if (cad[i] == carprev) nueva += (cad[i] == '0' ? '1' : '0');
                nueva += cad[i];

                // Actualizamos el caracter previo
                carprev = cad[i];
            }

            cout << nueva << endl;
        }
        else cout << cad << endl;
        
    }
    return 0;
}