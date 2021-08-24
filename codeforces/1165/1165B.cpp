#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define rforn(a, n) for(int a = (n)-1; a>=0; --a)
using namespace std;

int main()
{
    int n, este;
    cin>>n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        cin>>este;
        v.push_back(este);
    }
    sort(v.begin(), v.end());
    int res = 0;
    int index = 1;
    for(int i = 0; i < n; i++)
    {
        if(index <= v[i]) {res++; index++;}
    }
    cout<<res<<endl;
}