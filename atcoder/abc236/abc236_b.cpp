//
//  abc236_b.cpp
//  Problems
//
//  Created by NicolasCardozo on 1/02/22.
//  Copyright © 2022 NicolasCardozo. All rights reserved.
//

#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> count(n+1);
    for(int i=0; i < 4*n-1; i++) {
        int num;
        cin >> num;
        count[num] +=1;
    }
    for(int i=1; i<n+1; i++) {
        if(count[i] == 3) {
            cout << i << endl;
        }
    }
    
    return 0;
}
