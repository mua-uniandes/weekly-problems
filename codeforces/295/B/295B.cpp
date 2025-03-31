#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
/**
    @author: ddi4z
*/

int main() {
    ll n;
    cin >> n;

    vector<vector<ll>> graph(n, vector<ll>(n));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<ll> order(n);
    
    for (ll i = 0; i < n; i++) {
        cin >> order[i];
        order[i]--;
    }
    reverse(order.begin(), order.end());

    vector<ll> res(n, 0);

    for (ll k = 0; k < n; k++) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                if (graph[order[i]][order[j]] > (graph[order[i]][order[k]] + graph[order[k]][order[j]])) {
                    graph[order[i]][order[j]] = graph[order[i]][order[k]] + graph[order[k]][order[j]];
                }
                if (max(i, j) <= k) {
                    res[k] += graph[order[i]][order[j]];
                }
            }
        }
    }

    for (ll i = n - 1; i >= 0; i--) {
        cout << res[i];
        if (i > 0) cout << " ";
    }

    cout << "\n";
    return 0;
}