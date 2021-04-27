//
//  1029B.cpp
//  Problems
//
//  Created by NicolasCardozo on 4/20/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> problems(n);
    for(int i=0; i<n; i++)
        cin >> problems[i];
    int maxcount = 0;
    for(int i = 0; i<n; i++) {
        int j = i;
        while(j+1 < n && problems[j+1] <= 2*problems[j])
            j++;
        maxcount = max(maxcount, j-i+1);
        i=j;
    }
    cout << maxcount << endl;
    return 0;
}
