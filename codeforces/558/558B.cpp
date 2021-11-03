/*
ID: c4ts0up
LANG: C++
TASK: MUA 6 - A
URL: https://vjudge.net/contest/464789#problem/A
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
int n;
vector <int> arr;

unordered_map <int, int> primera, ultima, f;

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/

    cin >> n;
    arr.resize(n);
    for (int i=0; i<n; i++) cin >> arr[i];

    // leo de adelante hacia atras
    for (int i=0; i<n; i++) {
        if (primera.count(arr[i])) continue;
        else primera[arr[i]] = i;
    }

    // leo de atrás hacia adelante
    for (int i=n-1; i>=0; i--) {
        if (ultima.count(arr[i])) continue;
        else ultima[arr[i]] = i;
    }

    // cuento todo
    for (int i=0; i<n; i++) f[arr[i]]++;

    // encuentro el máximo
    int maxif = 0;
    for (auto it=f.begin(); it!=f.end(); ++it) maxif = max(maxif, it->second);

    // encuentro la pareja con la distancia más pequeña y que cumpla con el conteo
    int l = 0, r = n;
    for (pair <int,int> p : f) {
        int llave = p.ff;
        if (f[llave] == maxif) {
            if (ultima[llave] - primera[llave] < r - l) r = ultima[llave], l = primera[llave];
        }
    }

    cout << l+1 << " " << r+1 << endl;
    return 0;
}