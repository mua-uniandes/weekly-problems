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
    int from = 0, to;
    while(from < see.size() && see[from] == 'a') ++from;
    to = from;
    while(to < see.size() && see[to] != 'a') ++to;
    --to;
    if(from == see.size()) --from;
    convert(see,from,to);
    cout << see << "\n";
    return 0;
}
