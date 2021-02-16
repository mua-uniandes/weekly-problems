//
//  codeforces939A.cpp
//  Problems
//
//  Created by NicolasCardozo on 8/18/20.
//  Copyright © 2020 NicolasCardozo. All rights reserved.
//
 
#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> planes;
 
int main() {
    int num, plane;
    
    scanf("%d", &num); //cin >> num;
    for(int i=0; i<num; i++) {
        scanf("%d", &plane);
        planes.push_back(plane-1);
    }
    for(int j=0; j<num; j++) {
        if(j == planes[planes[planes[j]]]) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}