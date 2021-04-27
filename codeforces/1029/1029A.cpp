//
//  1029A.cpp
//  Problems
//
//  Created by NicolasCardozo on 4/16/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    //s to array
    int j=0;
    vector<int> prefix(n);
    for(int i=1; i<s.size(); i++) {
        j = prefix[i-1];
        while(j>0 && s[j] != s[i]) {
            j = prefix[j-1];
        }
        if(s[i] == s[j])
            ++j;
        prefix[i]=j;
    }
    
    cout << s;
    string sub = s.substr(j, s.size());
    for(int i=0; i<k-1; i++)
        cout << sub;
    cout << endl;
    
    return 0;
}


