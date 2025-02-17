#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
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
 
#define DBG(X) cout << #X << " = " << X << endl;
#define RAYA cout << " ========================= " << endl;
 
template<typename T>
ostream & operator <<(ostream &os, const vector<T> &v){
    os << "[";
    fori(i, 0, v.size()){
        if (i > 0) os << ",";
        os << v[i];
    }
    return os << "]";
}
 
const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 1;
const ld EPS = 1e-9;
 
void IOS(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    IOS();
    int n, k;
    cin >> n >> k;
    vi a(n);
    ll ans = 0;
    fori(i, 0, n) cin >> a[i];
    
    fori(i, 1, n){
        if (a[i - 1] + a[i] < k){
            ll sum = k - (a[i - 1] + a[i]);
            ans += sum;
            a[i] += sum; 
        } 
    }
    
    cout << ans << "\n";
    fori(i, 0, n){
        cout << a[i] << " ";
    }
    cout << "\n";
    
    

    return 0;
}