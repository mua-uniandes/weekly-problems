
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
    string see;
    cin >> see;
    int k; cin >> k;
    set<string> seen;
    for(int i = 0; i < see.size();++i) {
        string temp;
        for (int j = 0; j < k && i + j < see.size(); ++j) {
            temp += see[j + i];
            seen.insert(temp);
        }
    }
    string ans;
    for(auto &va:seen){
        --k;
        if(k == 0){
            ans = va;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
