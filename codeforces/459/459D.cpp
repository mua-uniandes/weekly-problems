//
//  459D.cpp
//  Problems
//
//  Created by NicolasCardozo on 11/2/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
const int MAX = 1000005;
int a[MAX], tmp[MAX], cnt[MAX], le[MAX], ri[MAX];

long long solve(int l, int r) {
    if (r - l < 2)
        return 0;
    int mid = (l + r) / 2;
    long long ret = solve(l, mid) + solve(mid, r);
    int p1 = l, p2 = mid;
    while (p1 != mid || p2 != r) {
        int val1 = (p1 < mid ? le[p1] : INF);
        int val2 = (p2 < r ? ri[p2] : INF);
        if (val1 <= val2) {
            p1++;
            ret += p2 - mid;
        }
        else
            p2++;
    }
    merge(le + l, le + mid, le + mid, le + r, tmp);
    for (int i = 0; i < r - l; i++)
        le[i + l] = tmp[i];
    merge(ri + l, ri + mid, ri + mid, ri + r, tmp);
    for (int i = 0; i < r - l; i++)
        ri[i + l] = tmp[i];
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tmp[i] = a[i];
    }
    sort(tmp, tmp + n);
    for (int i = 0; i < n; i++)
        a[i] = lower_bound(tmp, tmp + n, a[i]) - tmp;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        le[i] = cnt[a[i]];
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = n - 1; i >= 0; i--) {
        cnt[a[i]]++;
        ri[i] = cnt[a[i]];
    }
    cout << solve(0, n) << endl;
    return 0;
}
