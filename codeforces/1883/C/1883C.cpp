//  D - Raspberries

/**
    @author: Carlos Peña
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

// Int vectors
typedef vector<int> vi;
typedef vector<ll> vll;

// Int vectors of vectors
typedef vector<vi> vvi;
typedef vector<vll> vvll;

// Defs
#define fori(i, s, n) for(int i = s; i < n; i++)
#define DBG(X) cerr << #X << " = " << X << endl;
#define RAYA cerr << " ========================= " << endl;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--) {
        ll n,k;
        cin >> n >> k;
        ll a[n];
        fori(i,0,n) cin >> a[i];

        ll min = INT_MAX;
        if (k==2) {
            min = 1;
            fori(i,0,n) {
                if (a[i]%2 == 0) {
                    min = 0;
                    break;
                }
            }
        } else if (k==3) {
            fori(i,0,n) {
                if (a[i]%3 == 0) {
                    min = 0;
                    break;
                }
                if (a[i] == 1 && min > 2) min = 2;
                else if (a[i] == 2 && min > 1) min = 1;
                else if (min > k-a[i]%k) min = k-a[i]%k;
            }
        } else if (k==4) {
            int mul2 = 0;
            int odd = 0;
            fori(i,0,n) {
                if (a[i]%4 == 0) {
                    min = 0;
                    break;
                }
                if (a[i] == 1) {
                    if (min > 3) min = 3;
                    odd++;
                }
                else if (a[i] == 2) {
                    mul2++;
                    if (mul2 > 1) min = 0;
                } else if (a[i]%2 == 0) {
                    mul2++;
                    if (mul2 > 1) min = 0;
                }
                else if (a[i] == 3 && min > 1) min = 1;
                else if (min > k-a[i]%k) min = k-a[i]%k;
                if (a[i]%2 == 1) {
                    odd++;
                    if (odd > 1 && min > 2) min = 2;
                }
                if (mul2 > 0 && odd > 0 && min > 1) min = 1;
            }
        } else {
            fori(i,0,n) {
                if (a[i]%5 == 0) {
                    min = 0;
                    break;
                }
                if (a[i] == 1 && min > 4) min = 4;
                else if (a[i] == 2 && min > 3) min = 3;
                else if (a[i] == 3 && min > 2) min = 2;
                else if (a[i] == 4 && min > 1) min = 1;
                else if (min > k-a[i]%k) min = k-a[i]%k;
            }
        }
        cout << min << '\n';
    }
    return 0;
}