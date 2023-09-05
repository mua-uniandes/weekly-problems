#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    ios_base::sync_with_stdio(false);
    string see;
    cin >> see;
    vector<ll> left(see.size(),0),right(see.size(),0);
    for(int i = 0,co = 0;i < see.size();++i){
        if(see[i] == 'v') ++co;
        else
            left[i] = max(co-1,0),co = 0;
        if(i) left[i] += left[i-1];
    }
    for(int i = see.size()-1,co = 0; i > -1;--i){
        if(see[i] == 'v') ++co;
        else
            right[i] = max(co-1,0), co = 0;
        if(i != see.size()-1) right[i] += right[i+1];
    }
    ll ans = 0;
    for(int i = 0; i < see.size();++i){
        if(see[i] == 'o') ans += left[i]*right[i];
    }

    cout << ans << "\n";

    return 0;
}