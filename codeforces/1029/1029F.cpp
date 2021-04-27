//
//  1029F.cpp
//  Problems
//
//  Created by NicolasCardozo on 4/24/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

int lens[N];
int k;

long long solve(long long a, long long b){
    k = 0;
    for (long long i = 1; i * i <= b; ++i)
        if (b % i == 0)
            lens[k++] = i;
    
    long long ans = 2 * (a + b) + 2;
    long long x = a + b;
    int l = 0;
    for (long long i = 1; i * i <= x; ++i){
        if (x % i == 0){
            while (l + 1 < k && lens[l + 1] <= i)
                ++l;
            if (b / lens[l] <= x / i)
                ans = min(ans, (i + x / i) * 2);
        }
    }
    
    return ans;
}

int main() {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    printf("%lld\n", min(solve(a, b), solve(b, a)));
    return 0;
}

