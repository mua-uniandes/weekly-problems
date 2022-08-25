
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;


#define dsort(a)            sort(a,a+n,greater<int>())
#define vasort(v)           sort(v.begin(), v.end());
#define vdsort(v)           sort(v.begin(), v.end(),greater<int>());
#define uniquee(x)          x.erase(unique(x.begin(), x.end()),x.end())
#define pn                  cout<<endl;
#define md                  10000007


int main() {
    long long t;
    cin>>t;
    while(t--) {
        long long m,n,b,c,d,i,j,k,x,y,z,l,q,r,p;
        cin>>x>>y;
        long long a[x+1];
        for(long long i=0; i<x; i++)
			cin>>a[i];
        vector<pair<long long,long long> > v,f;
        ll mn=1e18, ans=0,sz;
        for(long long i=0; i<x; i++) {
            for(long long j=0; j<x; j++) {
                if(i !=j) {
                    d=abs(a[i]- a[j]) ;
                    if(mn>d )
                        mn=d, v.push_back(make_pair(i+1, j+1));
                }
            }
        }

        sort(v.begin(), v.end());
        long long minn = 1e18;

        for(long long i=0; i < v.size(); i++) {
            d=a[ v[i].first -1 ]   + a[v[i].second  -1  ];
            if( minn>d  )
                minn=d, p=v[i].first, q=v[i].second;
        }

        if(x>2  and x<=y) {
            d=y-x;

            for(long long i=0; i<x-1; i++) {
                f.push_back(make_pair(i+1, i+2));
                ans+=a[i]+a[i+1];
            }
            f.push_back(make_pair(x, 1));
            ans+=a[0]+a[x-1];

            while(d) {
                f.push_back(make_pair(p, q ));
                d--;
                ans+=a[ p -1 ]   + a[q  -1  ];
            }

            sz=f.size() ;
        } else        {
            ans=-1,  sz=0;
        }

        cout<<ans<<endl;
        fr(i, sz)  cout<<f[i].first<<" "<<f[i].second<<endl;
    }
    return 0;
}