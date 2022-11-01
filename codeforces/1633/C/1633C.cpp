/**
    @author: c4ts0up
    @language: C++
    @task: MUA 2 (2022-10) A
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
ll t, hc, dc, hm, dm;
ll k, w, a;

bool Check(ll hc, ll dc, ll hm, ll dm) {
    ll rondas_heroe = (hm%dc == 0 ? hm/dc : (hm/dc)+1);
    ll rondas_mon = (hc%dm == 0 ? hc/dm : (hc/dm)+1);
    //cerr << "Con hc = " << hc << ", dc = " << dc << ", hm = " << hm << ", dm = " << dm << ", el resultado es " << (rondas_heroe <= rondas_mon ? "VICTORIA" : "DERROTA") << endl;
    return rondas_heroe <= rondas_mon;
}

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/
    cin >> t;
    while (t--) {
        cin >> hc >> dc >> hm >> dm;
        cin >> k >> w >> a;

        bool win = false;

        for (int i=0; i<=k; i++) {
            if (Check(hc + a*i, dc + w*(k-i), hm, dm)) {
                win = true;
                break;
            }
        }

        cout << (win ? "YES" : "NO") << endl;
    }
    return 0;
}