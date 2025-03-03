/**
    @author: ddi4z
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

// integer vectors
typedef vector<int> vi;
typedef vector<ll> vll;

// vectors of vectors of integers
typedef vector<vi> vvi;
typedef vector<vll> vvll;

// pairs of integers
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

// vector of pairs of integers
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// stack of integers
typedef stack<int> si;

// stack of pairs of integers
typedef stack<pii> spii;

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fori(i, s, n) for(int i = s; i < n; ++i)
#define rfori(i, s, n) for(int i = s; i >= n; --i)

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 1;
const ld EPS = 1e-9;

#define DBG(X) cerr << #X << " = " << X << endl;
#define RAYA cerr << " ========================= " << endl;

// order statistics

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
//ordered_set order;


int mod(int a, int m) {return ((a%m) + m) % m;}

int main() {
    ll t, n, res;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        string s;
        cin >> s;
        res = n - 1;
        fori(i,1,n - 1){
            if (s[i - 1] == s[i + 1]){
                res--;
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}