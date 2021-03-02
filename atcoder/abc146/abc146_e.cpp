//
//  abc146_e.cpp
//  Problems
//
//  Created by NicolasCardozo on 2/26/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n, k, elem;
    cin >> n >> k;
    vector<int> array;
    for(int i=0; i<n; i++) {
        cin >> elem;
        array.push_back(elem % k);
    }
    vector<long long> prefix(n + 1, 0);
    for(int i=0; i<n; i++)
        prefix[i + 1] = prefix[i] + array[i];
    for(int i=0; i<=n; i++)
        prefix[i] = ((prefix[i] - i) % k + k) % k;
    
    map<long long, int> count;
    count.insert({0, 1});
    long long answer = 0;
    for(int i=1; i<=n; i++) {
        if (i - k >= 0) {
            count[prefix[i - k]] = count[prefix[i - k]] - 1;
        }
        answer += count[prefix[i]];
        count[prefix[i]] = count[prefix[i]] + 1;
    }
    cout << answer << endl;
    return 0;
}
