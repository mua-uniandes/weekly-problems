//
//  1029Ca.cpp
//  Problems
//
//  Created by NicolasCardozo on 4/24/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    multiset<int> l, r;
    pair<int, int> intervals[300010];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
        l.insert(intervals[i].first);
        r.insert(intervals[i].second);
    }
    int best = 0;
    for (int i = 0; i < n; ++i) {
        l.erase(l.find(intervals[i].first));
        r.erase(r.find(intervals[i].second));
        best = max(best, *r.begin() - *l.rbegin());
        l.insert(intervals[i].first);
        r.insert(intervals[i].second);
    }
    cout << best << endl;
    return 0;
}
