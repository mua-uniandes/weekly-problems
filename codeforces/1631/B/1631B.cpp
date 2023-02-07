#include<bits/stdc++.h>
using namespace std;

int find_rightmost_x(vector<int> &b){
    int n = (int)b.size() - 1;

    int x = 1;
    while( x + 1 <= n && b[x+1] == b[1] )
        x ++;

    return x;
}

void apply(vector<int> &b,int l,int r){
    int k = ( r - l + 1 ) / 2;
    for(int i=0; i<k; i++)
        b[l+k+i] = b[l+i];
}

int main(){

    int tc;
    cin >> tc;
    while( tc-- ){

        int n;
        cin >> n;

        vector<int> a(n+1);
        for(int i=1; i<=n; i++)
            cin >> a[i];

        vector<int> b = a;
        reverse(b.begin()+1,b.end());

        int ans = 0;
        while( find_rightmost_x(b) != n ){
            int x = find_rightmost_x(b);
            if( 2 * x > n ){
                apply(b,x-(n-x)+1,n);
                ans ++;
            }
            else{
                apply(b,1,2*x);
                ans ++;
            }
        }
        cout << ans << '\n';
    }


    return 0;
}