#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
//Definition Section
//--------------------------------------------------------------
#define fl(i,x,y) for(i=x; i<y; i++)
#define flc(i,x,y,z) for(i=x; i<y; i+=z)
#define nl cout<<endl
#define vsort(v) sort(v.begin(), v.end());
#define vsortg(v) sort(v.begin(), v.end(), greater<int>());
#define all(x) x.begin(),x.end()
#define pb push_back
//--------------------------------------------------------------
 
int main()
{
    ll n,m,t,i,j,k,x,y,z,a,b,c,cnt=0,result=0;
    bool flag=false;
    string s,s1,s2,s3;
 
    cin>>t;
 
    while(t--) {
     cin>>n;
    set<int> result[n];
    string str[n];
    fl(i,0,n){
        cin>>str[i];
    }
 
    fl(i,0,n){
        result[i].insert(i+1);
       fl(j,0,n){
            if(str[i][j]!='0'){
                result[j].insert(i+1);
            }
        }
    }
   fl(i,0,n){
        cout<<result[i].size()<<" ";
        //fl(x,0,result[i].size())
        for(auto x:result[i]) cout<<x<<" "; nl;
    }
 
    }
 
  //cout<<endl; main();
}
 
 