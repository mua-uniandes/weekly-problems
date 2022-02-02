//
//  abc236_e.cpp
//  Problems
//
//  Created by NicolasCardozo on 1/02/22.
//  Copyright © 2022 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
 
template <class T> T maximize(const vector<T>& a) {
    T s = 0, t = 0;
    for (const T& x : a) {
        const T u = max(s, t) + x;
        s = t;
        t = u;
    }
    return max(s, t);
}
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    {
        double ok = 1.0, ng = 1e9 + 1.0;
        vector<double> b(n);
        while ((ng - ok) / ng > 1e-3) {
            const double md = sqrt(ok * ng);
            for (int i = 0; i < n; ++i) {
                b[i] = a[i] - md;
            }
            if (maximize(b) >= 0.0) {
                ok = md;
            } else {
                ng = md;
            }
        }
        cout << fixed << setprecision(12);
        cout << ok << '\n';
    }
    {
        int ok = 1, ng = 1000000000 + 1;
        vector<int> b(n);
        while (ng - ok > 1) {
            const int md = (ok + ng) / 2;
            for (int i = 0; i < n; ++i) {
                b[i] = a[i] >= md ? 1 : -1;
            }
            if (maximize(b) > 0) {
                ok = md;
            } else {
                ng = md;
            }
        }
        cout << ok << '\n';
    }
    return 0;
}
