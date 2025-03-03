//  B - Common Divisors

/**
    @author: Carlos Peña
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

    string s1, s2;

    cin >> s1 >> s2;

    vi lenDivisors1;
    set<string> divisors1;
    fori(i,1,s1.length()+1) if (s1.length()%i == 0) lenDivisors1.push_back(i);

    // Divisors for s1
    for (int i: lenDivisors1) {
        string subi = s1.substr(0,i);
        bool isDivisor = true;
        for (int j=0;j<s1.length();j+=i) {
            string subj = s1.substr(j,i);
            if (subi != subj) {
                isDivisor = false;
                break;
            }
        }
        if (isDivisor) divisors1.insert(subi);
    }

    vi lenDivisors2;
    set<string> divisors2;
    fori(i,1,s2.length()+1) if (s2.length()%i == 0) lenDivisors2.push_back(i);

    // Divisors for s2
    for (int i: lenDivisors2) {
        string subi = s2.substr(0,i);
        bool isDivisor = true;
        for (int j=0;j<s2.length();j+=i) {
            string subj = s2.substr(j,i);
            if (subi != subj) {
                isDivisor = false;
                break;
            }
        }
        if (isDivisor) divisors2.insert(subi);
    }

    set<string> commonDivisors;
    set_intersection(divisors1.begin(),divisors1.end(),
        divisors2.begin(),divisors2.end(),
        inserter(commonDivisors,commonDivisors.begin()));

    cout << commonDivisors.size();
    return 0;
}