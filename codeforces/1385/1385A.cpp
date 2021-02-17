#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        vector<int> nums(3);
        scanf(" %d %d %d",&nums[0],&nums[1],&nums[2]);
        sort(nums.begin(),nums.end());
        if(nums[0] == nums[1] && nums[0] == nums[2])
            printf("YES\n%d %d %d\n",nums[0],nums[0],nums[0]);
        else if(nums[1] == nums[2])
            printf("YES\n%d %d %d\n",nums[0],nums[0],nums[1]);
        else puts("NO");
    }
    return 0;
}