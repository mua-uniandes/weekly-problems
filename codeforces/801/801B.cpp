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
    string x, y, z = "";
    cin>>x>>y;
    
    for(int i = 0; i < x.length(); i++)
    {
        if(x[i] < y[i]) {cout<<-1<<endl; y = ""; break;}
    }
    
    cout<<y<<endl;
}