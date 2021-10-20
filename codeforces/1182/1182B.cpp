/*
ID: c4ts0up
LANG: C++
TASK: 
URL: 
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

const ll MOD = 1e9+7, NMAX = 600;


int h, w;
char grid[NMAX][NMAX];
pair <int,int> centro;
set <pair <int,int> > ast;

void RecogerAst() {
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) if (grid[i][j] == '*') ast.insert({i, j});
    }
}

bool EncontrarCentral() {
    int cnt = 0;

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (grid[i][j] == '*'
                && i+1 < h && grid[i+1][j] == '*'
                && i-1 >= 0 && grid[i-1][j] == '*'
                && j+1 < w && grid[i][j+1] == '*'
                && j-1 >= 0 && grid[i][j-1] == '*') cnt++, centro = {i,j};
        }
    }

    return cnt == 1;
}


int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/

    cin >> h >> w;
    for (int i=0; i<h; i++) {
        string temporal;
        cin >> temporal;
        for (int j=0; j<w; j++) grid[i][j] = temporal[j];
    }

    RecogerAst();
    //cerr << "Se encontraron " << ast.size() << " asteriscos" << endl;

    if (!EncontrarCentral()) cout << "NO" << endl;
    else {
        bool flag = true;
        set <pair <int,int> > der, izq, sup, inf;

        for (pair <int,int> a : ast) {
            // Misma fila
            if (a.ff == centro.ff) {
                if (a.ss < centro.ss) izq.insert(a);
                else if (a.ss > centro.ss) der.insert(a);
            }
            else if (a.ss == centro.ss) {
                if (a.ff < centro.ff) sup.insert(a);
                else if (a.ff > centro.ff) inf.insert(a);
            }
            else flag = false;
        }

        // Verificamos la integridad de las partes
        pair <int,int> previo;
        izq.insert(centro);
        der.insert(centro);
        sup.insert(centro);
        inf.insert(centro);

        // Izquierda
        previo = *izq.begin();
        for (pair <int,int> p : izq) {
            if (p.ss - previo.ss > 1) flag = false;
            previo = p;
        }
        // Derecho
        previo = *der.begin();
        for (pair <int,int> p : der) {
            if (p.ss - previo.ss > 1) flag = false;
            previo = p;
        }
        // Superior
        previo = *sup.begin();
        for (pair <int,int> p : sup) {
            if (p.ff - previo.ff > 1) flag = false;
            previo = p;
        }
        // Izquierda
        previo = *inf.begin();
        for (pair <int,int> p : inf) {
            if (p.ff - previo.ff > 1) flag = false;
            previo = p;
        }

        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}