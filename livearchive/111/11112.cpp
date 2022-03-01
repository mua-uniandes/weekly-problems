//
//  11112.cpp
//  Problems
//
//  Created by NicolasCardozo on 8/9/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int pot, bet, fpot;
    while(scanf("%d %d %d", &pot, &bet, &fpot) == 3) {
        if(pot + bet + fpot == 0)
            break;
        if(abs(fpot - pot)%bet) {
            puts("No accounting tablet");
            continue;
        }
        int diff = abs(fpot - pot) / bet;
        int cnt = diff/3 + (diff%3 ? 1 : 0);
        printf("%d\n", cnt);
    }
    return 0;
}
