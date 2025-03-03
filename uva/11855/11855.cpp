#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fori(i, s, n) for(int i = s; i < n; ++i)
#define rfori(i, s, n) for(int i = s; i >= n; --i)

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 1;
const ld EPS = 1e-9;
const int primo = 263;

void IOS() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll calcularHash(const string &str, int len, ll primo_potencia) {
    ll hash = 0;
    fori(i, 0, len) {
        hash = (hash * primo + (str[i] - 'A' + 1)) % MOD;
    }
    return hash;
}

int main() {
    char s[1005]; 
    while (scanf("%[^\n]%*c", s) == 1) {

        int n = 0;
        for (int i = 0; s[i]; ++i) {
            if (s[i] != ' ') {
                s[n++] = s[i];
            }
        }
        s[n] = '\0'; 

        vector<ll> primo_potencias(n + 1, 1);
        fori(i, 1, n + 1) {
            primo_potencias[i] = (primo_potencias[i - 1] * primo) % MOD;
        }

        fori(len, 1, n) {
            unordered_map<ll, int> mp;
            ll mxReps = -1;
            ll mxHash = -1;


            ll hash = calcularHash(s, len, primo_potencias[len]);
            mp[hash]++;
            mxReps = 1;
            mxHash = hash;

        
            fori(i, 1, n - len + 1) {
                hash = (hash - (s[i - 1] - 'A' + 1) * primo_potencias[len - 1] % MOD + MOD) % MOD;
                hash = (hash * primo + (s[i + len - 1] - 'A' + 1)) % MOD;
                mp[hash]++;
                if (mp[hash] > mxReps) {
                    mxReps = mp[hash];
                    mxHash = hash;
                }
            }

            if (mxReps <= 1) break;
            printf("%lld\n", mxReps);
        }

        printf("\n");
    }

    return 0;
}