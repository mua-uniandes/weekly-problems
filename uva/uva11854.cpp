//
//  uva11854.cpp
//  Problems
//
//  Created by NicolasCardozo on 6/3/19.
//  Copyright © 2019 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265

int main() {
    int arr[3];
    int n = sizeof(arr)/sizeof(arr[0]);
    while(true) {
        cin >> arr[0] >> arr[1] >> arr[2];
        if(arr[0] == 0 && arr[1] == 0 && arr[2]==0) {
            return 0;
        } else {
            sort(arr, arr + n);
            if(arr[0]*arr[0] + arr[1]*arr[1] == arr[2]*arr[2]) {
                cout << "right\n";
            } else {
                cout << "wrong\n";
            }
        }
    }
    return 0;
}
