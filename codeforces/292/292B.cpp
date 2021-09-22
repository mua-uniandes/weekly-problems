//
//  292B.cpp
//  Problems
//
//  Created by NicolasCardozo on 9/14/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;
    int arr[1000000] = {0};
    int u, v;
    while(m) {
        cin >> u >> v;
        arr[u] ++;
        arr[v] ++;
        m--;
    }
    int size =  sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + size, greater<int>());
    if(arr[0] > 2 && arr[1] == 1 && arr[n-1] == 1)
        cout << "star topology" << endl;
    else if(arr[0] == 2 && arr[n-1] == 1)
        cout << "bus topology" << endl;
    else if(arr[0] == 2 && arr[n-1] == 2)
        cout << "ring topology" << endl;
    else
        cout << "unknown topology" << endl;
    return 0;
}
