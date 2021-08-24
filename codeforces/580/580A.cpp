#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
n++;n--;
    int res = 1;
    int count = 1;
    int este = 0; int prev;
    cin>>este;
    for(int i = 1; i < n; i++)
    {
        prev = este;
        cin>>este;
        if(este >= prev) count++;
        else count = 1;
        res = max(res, count);
    }
    cout<<res<<endl;
}