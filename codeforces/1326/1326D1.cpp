// God is with me
#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

vector<int> d1,d2;

void manacher(string &s){
    d1.clear();d2.clear();
    d1.resize(s.size(),0);d2.resize(s.size(),0);
    int n = s.size();
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
}


string bestPalFrom(int l, int r,string &s){
    string ans = "";

    for(int i = l+1; i < r;++i){
        if((i+d1[i]-1 >= r-1 || i - d1[i]+1 <= l+1) && (min((i-l)*2-1,(r-i)*2-1) > ans.size())){
            if((i-l)*2-1< (r-i)*2-1)
                ans = s.substr(l+1,(i-l)*2-1);
            else
                ans = s.substr(i-(r-i)+1,(r-i)*2-1);
        }
        if(d2[i] != 0 && (i+d2[i]-1 >= r-1 || i - d2[i] <= l+1) && (min((i-l-2)*2+2,(r-i)*2) > ans.size())){
            if((i-l-2)*2+2 < (r-i)*2)
                ans = s.substr(l+1,(i-l-2)*2+2);
            else
                ans = s.substr(i-(r-i),(r-i)*2);
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string see;
        cin >> see;
        manacher(see);
        string ans = bestPalFrom(-1,see.size(),see);
        int i = 0,j = see.size()-1;
        string temp = "";
        while(see[i] == see[j] && i < j){
            temp += see[i];
            string lol = bestPalFrom(i,j,see);
            if(temp.size()*2 + lol.size() > ans.size()){
                string lil = temp;
                reverse(lil.begin(),lil.end());
                ans = temp + lol + lil;
            }
            ++i,--j;
        }
        cout << ans << "\n";
    }
    return 0;
}