//
//  abc187_c.cpp
//  Problems
//
//  Created by NicolasCardozo on 1/29/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
 
using namespace std;

int main(){
    int n;
    scanf("%d ", &n);
    vector<string> S(n);
    for(string &s : S) {
        cin >> s;
    }
    unordered_set<string> set(S.begin(), S.end());
    for(string& s : S)
        if(set.count('!' + s)) {
            cout << s << endl;
            return 0;
        }
    printf("satisfiable\n");
    return 0;
}
