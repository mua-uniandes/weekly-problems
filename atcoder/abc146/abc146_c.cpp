//
//  abc146_c.cpp
//  Problems
//
//  Created by NicolasCardozo on 2/23/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    long long a, b, x, max = 1e9, min = 0;
    cin >> a >> b >> x;
    if(x >= a*max + b*int(log10(max) + 1))
        cout << max << endl;
    else {
        long long n = 0;
        while(max - min > 1) {
             n = floor((max + min) / 2);
            if(x >= a*n + b*int(log10(n) + 1))
                min = n;
            else
                max = n;
        }
        cout << min << endl;
    }
    return 0;
}

