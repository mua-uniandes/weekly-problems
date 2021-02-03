//
//  abc187_b.cpp
//  Problems
//
//  Created by NicolasCardozo on 1/26/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> points(n);
    for(auto& [x,y] : points)
        cin >> x >> y;
    int ans = 0;
    for(int i=0; i<n; ++i)
        for(int j=i+1; j<n; ++j)
            if(abs(points[i].second-points[j].second) <= abs(points[i].first - points[j].first))
                ans++;
    
    cout << ans << endl;
    
    return 0;
}
