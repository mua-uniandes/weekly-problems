#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string fi,se;
        cin >> fi >> se;
        reverse(se.begin(),se.end());
        bool ans = 0;
        for(int i = 0; i < fi.size() && !ans;++i){
            int j = 0;
            while(j < se.size() && i + j < fi.size() && !ans && se[j] == fi[i+j]){
                int tempJ = j+1;
                int tempI = i+j-1;
                while(tempI > -1 && tempJ < se.size() && se[tempJ] == fi[tempI]){
                    ++tempJ;
                    --tempI;
                }

                if(tempJ == se.size()) ans = 1;
                ++j;
            }
        }

        if(ans) puts("YES");
        else puts("NO");
    }
    return 0;
}