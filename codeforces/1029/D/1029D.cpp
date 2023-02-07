//
//  1029D.cpp
//  Problems
//
//  Created by NicolasCardozo on 4/24/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 100000;

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int array[N];
    int powers[11];
    int lengths[N];
    for(int i=0; i<n; i++)
        cin >> array[i];
    
    powers[0] = 1;
    for(int i=0; i<10; i++)
        powers[i + 1] = powers[i] * 10 % k;
    
    vector<int> reminders[11];
    for(int i=0; i<n; i++){
        int x = array[i];
        while (x > 0){
            ++lengths[i];
            x /= 10;
        }
        reminders[lengths[i]].push_back(array[i] % k);
    }
    
    for(int i=0; i<10; i++)
        sort(reminders[i].begin(), reminders[i].end());
    
    long long ans = 0;
    for(int i=0; i<n; i++) {
        for (int j = 1; j <10; ++j) {
            int rem = (array[i] * (long long)(powers[j])) % k;
            int xrem = (k - rem) % k;
            auto l = lower_bound(reminders[j].begin(), reminders[j].end(), xrem);
            auto r = upper_bound(reminders[j].begin(), reminders[j].end(), xrem);
            ans += (r - l);
            if (lengths[i] == j && (rem + array[i] % k) % k == 0)
                --ans;
        }
    }
    cout << ans <<endl;
    return 0;
}

