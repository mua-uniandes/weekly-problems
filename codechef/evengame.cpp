//
//  evengame.cpp
//  Problems
//
//  Created by NicolasCardozo on 3/7/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int cases, n;
    long long ai;
    cin >> cases;
    for(int i=0; i<cases; i++) {
        cin >> n;
        long long sum = 0;
        for(int j=0; j<n; j++) {
            cin >> ai;
            sum += ai;
        }
        if(sum % 2 == 0)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    return 0;
}

