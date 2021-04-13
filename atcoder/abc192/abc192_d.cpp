//
//  abc192_d.cpp
//  Problems
//
//  Created by NicolasCardozo on 4/6/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

string x;
long long m;
vector<int> arr;

long long f(long long base){
    long long res = 0;
    for(char c : x){
        if(res > m / base) return 0;
        res *= base;
        res += c;
    }
    return res <= m;
}

int main() {
    cin >> x;
    cin >> m;
    
    for(char& c : x) c -= '0';
    if (x.size() == 1)
        cout << f(10) << endl;
    else {
        long long d = *max_element(x.begin(), x.end());
        long long low = d;
        long long high = 1.1e18;
        while (high - low > 1) {
            long long mid = (low + high) / 2;
            if (f(mid))
                low = mid;
            else
                high = mid;
        }
        cout << low - d << endl;
    }
    return 0;
}
