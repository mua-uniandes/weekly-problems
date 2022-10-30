#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int ones = 0, twos = 0;
        while(n--){
            int val; scanf(" %d",&val);
            if(val == 2) ++twos;
            else ++ones;
        }
        //printf("%d %d\n",ones,twos);
        if(ones&1){puts("NO");continue;}
        if(twos%2 == 0 || (ones > 1)){puts("YES");}
        else puts("NO");
    }
    return 0;
}