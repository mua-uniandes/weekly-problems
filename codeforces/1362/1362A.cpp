#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        int ans=0;
        cin>>a>>b;
        if(a>b) swap(a,b);
        bool flag=0;
        int cnt=0;
        while(a<b)
        {
            cnt++;
            a*=2;
        }
        if(a>b)
        {
            cout<<-1<<endl;
            continue;
        }
        else
        {
            ans+=cnt/3;
            cnt%=3;
            ans+=cnt/2;
            cnt%=2;
            ans+=cnt;
        }
        cout<<ans<<endl;
    }
    return 0;
}