/*
ID: c4ts0up
LANG: C++
TASK: MUA 3 - E - Mocha and Hiking
URL: https://vjudge.net/contest/455358#problem/E
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
vector <int> arr;

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/

    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n+1);
        for(int i=1; i<=n; i++) cin >> arr[i];

        // 1 -> IN
        if (arr[1]) {
            cout << n+1 << " ";
            for (int i=1; i<=n; i++) cout << i << " ";
            cout << endl;
        }
        // N -> OUT
        else if (!arr[n]) {
            for (int i=1; i<=n; i++) cout << i << " ";
            cout << n+1 << endl;
        }
        else {
            int consec = -1;

            for (int i=1; i<=n-1; i++) {
                // OUT-IN
                if (!arr[i] && arr[i+1]) {
                    consec = i;
                    break;
                }
            }

            if (consec == -1) {
                for (int i=1; i<=n; i++) cout << i << " ";
                cout << endl;
            }
            else {
                for (int i=1; i<=consec; i++) cout << i << " ";
                cout << n+1 << " ";
                for (int i=consec+1; i<=n; i++) cout << i << " ";
                cout << endl;
            }
        }
    }
    return 0;
}