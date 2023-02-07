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

ll t, n, m;
int matriz[55][55];

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/

    cin >> t;
    while (t--) {
        cin >> n >> m;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) cin >> matriz[i][j];
        }

        int filas_vacias = 0, cols_vacias = 0;

        for (int i=0; i<n; i++) {
            int suma = 0;
            for (int j=0; j<m; j++) suma += matriz[i][j];
            if (!suma) filas_vacias++;
        }

        for (int j=0; j<m; j++) {
            int suma = 0;
            for (int i=0; i<n; i++) suma += matriz[i][j];
            if (!suma) cols_vacias++;
        }

        //cerr << filas_vacias << "; " << cols_vacias << endl;
        int celdas_vacias = min(filas_vacias, cols_vacias);

        cout << (celdas_vacias % 2 == 1 ? "Ashish" : "Vivek") << endl;
    }
    return 0;
}