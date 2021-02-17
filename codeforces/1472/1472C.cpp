#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        ll nums[n];
        for(int i = 0; i < n;++i) scanf(" %lld",&nums[i]);
        ll ans = nums[n-1];
        for(int i = n-2; i > -1;--i){
            if(i + nums[i] < n)
                nums[i] += nums[i+nums[i]];
            ans = max(ans,nums[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}