//  A - Li Hua and Maze

/**
    @author: Carlos Peña     a
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

// Int vectors
typedef vector<int> vi;
typedef vector<ll> vll;

// Int vectors of vectors
typedef vector<vi> vvi;
typedef vector<vll> vvll;

// Defs
#define fori(i, s, n) for(int i = s; i < n; i++)
#define DBG(X) cerr << #X << " = " << X << endl;
#define RAYA cerr << " ========================= " << endl;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        ll n,m;
        cin >> n >> m;

        ll x1,y1,x2,y2;

        cin >> x1 >> y1 >> x2 >> y2;

        ll min = 1000000000000;

        // Case trapping x1,y1

        // Case when arist x1,y1
        if (x1==1 or y1==1 or x1==n or y1==m) {
            if (min > 3) min = 3;
            if (x1==1 and y1==1) min = 2;
            if (x1==n and y1==1) min = 2;
            if (x1==1 and y1==m) min = 2;
            if (x1==n and y1==m) min = 2;
        }

        // Case trapping x2,y2

        // Case when arist x2,y2
        if (x2==1 or y2==1 or x2==n or y2==m) {
            if (min > 3) min = 3;
            if (x2==1 and y2==1) min = 2;
            if (x2==n and y2==1) min = 2;
            if (x2==1 and y2==m) min = 2;
            if (x2==n and y2==m) min = 2;
        }

        if (min > 4) min = 4;

        cout << min << '\n';
    }
    
    return 0;
}