/**
    @author: c4ts0up
    @language: C++
    @task: MUA 5B 2022-10
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
ll n, k;
string cad, res;

ll dist(char a, char b) {
    return abs(int(a-b));
}

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/
    cin >> n >> k;
    cin >> cad;

    for (char ch : cad) {
        // ya completamos la distancia necesaria
        if (!k) res += ch;

        // maximizar distancia
        else if (k >= max(dist(ch, 'a'), dist(ch, 'z'))) {
            if (dist(ch, 'a') > dist(ch, 'z')) {
                res += 'a';
                k -= dist(ch, 'a');
            }

            else {
                res += 'z';
                k -= dist(ch, 'z');
            }
        }

        // está en el rango
        else {
            // vamos hacia adelante
            if (ch + k <= 'z') {
                res += char(ch + k);
                k -= dist(ch, char(ch + k));
            }
            // vamos hacia atrás
            else if (ch - k >= 'a') {
                res += char(ch - k);
                k -= dist(ch, char(ch - k));
            }
            // este caso no existe ya que se revisó en el primer if
            else {
                cerr << "ERROR" << endl;
            }
        }
    }

    if (k) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}