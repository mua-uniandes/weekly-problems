include <bits/stdc++.h>
using namespace std ;

int T, n, w, h, sz ;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
    if(a.first==b.first) return a.second<b.second ;
    else return a.first>b.first ;
}

int main() {
    cin>> T ;
    while(T--) {
        vector<pair<int, int>> dolls ;
        cin>> n ;
        for(int i=0 ; i<n ; i++) {
            cin>> w >> h ;
            dolls.push_back(make_pair(w, h)) ;
        }
        sort(dolls.begin(), dolls.end(), cmp) ;
        vector<int> c(n+1), dp(n+1), array(n+1) ;
        for(int i=0 ; i<n ; i++)
          array[i]=dolls[i].second ;
        sz=1 ;
        c[1]=array[0];
        dp[0]=1 ;
        for(int i=1 ; i<dolls.size() ; i++)  {
           if(array[i]<c[1]) {
              c[1]=array[i] ;
              dp[i]=1 ;
           } else if(array[i]>=c[sz]) {
              c[sz+1]=array[i] ;
              dp[i]=sz+1 ;
              sz++ ;
           } else {
              int k=upper_bound(c.begin(), c.begin()+sz, array[i])-c.begin() ;
              c[k]=array[i] ;
              dp[i]=k ;
           }
        }
        cout<< dp[max_element(dp.begin(), dp.end())-dp.begin()] << endl ;
    }
}