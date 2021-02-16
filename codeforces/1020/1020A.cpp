//
//  main.cpp
//  buildings.cpp
//
//  Created by NicolasCardozo on 8/14/18.
//  Copyright © 2018 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;


int main(int argc, const char * argv[]) {
    int n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;
    for(int i=0; i<k; i++) {
        int fa, fb, ta, tb;
        cin >> ta >> fa >> tb >> fb;
        if(ta == tb)
            cout << abs(fa - fb) << "\n";
        else {
        if (fa < a)
            cout << a - fa + abs(ta - tb) + abs(fb - a) << "\n";
        else if(fa > b)
            cout << fa - b + abs(ta - tb) + abs(fb -b) << "\n";
        else
            cout << abs(fa - fb) + abs(ta - tb) << "\n";
        }
    }
    return 0;
}
