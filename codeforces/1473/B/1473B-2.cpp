// Is love even real?
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
//const int N = 1e5+20;
const ld eps = 1e-9;
const ll mod = 998244353;
const ll lel = 1e12;

bool good(string &a, string &b){
    bool ans = 1;
    for(int i = 0; i < a.size() && ans;i += b.size()){
        if(a.substr(i,b.size()) != b)
            ans = 0;
    }

    return ans;
}

int lcm(int a, int b){
    return a*(b/__gcd(a,b));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    while(q--){
        string a,b; cin >> a >> b;
        if(a.size() < b.size()) swap(a,b);
        int check = lcm(a.size(),b.size());
        string send = a;
        while(send.size() != check)
            send += a;

        if(good(send,b))
            cout << send << "\n";
        else cout << -1 << "\n";
    }

    return 0;
}
