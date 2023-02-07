// Is love even real?
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ll long long
#define ss second
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

void convert(string &see, int from, int to){
    for(int i = from; i <= to;++i){
        int val = see[i]-'a'-1;
        if(val < 0) val = 25;
        see[i] = val +'a';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_map<string,ll> mp;
        ll ans = 0;
        for(int i = 0; i < n;++i){
            string see;
            cin >> see;
            string temp1 = see, temp2 = see;
            temp1[0] = temp2[1] = '*';
            ans += mp[temp1];
            ans += mp[temp2];
            ans -= mp[see];
            mp[see]+=2LL;
            ++mp[temp1];
            ++mp[temp2];
        }
        cout << ans << "\n";
    }
    return 0;
}
