//
//  1029Cb.cpp
//  Problems
//
//  Created by NicolasCardozo on 4/24/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 300005;
pair <int, int> p[N], tree[4*N];

void build(int idx, int st, int nd) {
    if (st == nd)
        tree[idx] = p[st];
    else {
        int mid = (st + nd) >> 1;
        build(1+(idx<<1), st, mid);
        build(2+(idx<<1), mid + 1, nd);
        if (max(tree[1+(idx<<1)].first, tree[2+(idx<<1)].first) >
            min(tree[1+(idx<<1)].second, tree[2+(idx<<1)].second)){
            tree[idx] =  {-1, -1};
        } else {
            tree[idx] = {max(tree[1+(idx<<1)].first, tree[2+(idx<<1)].first),
                         min(tree[1+(idx<<1)].second, tree[2+(idx<<1)].second)};
        }
    }
}

pair <int, int> get(int idx, int st, int nd, int l, int r) {
   if (l > r)
       return {0, 1000000000};
    if (l <= st && nd <= r)
       return tree[idx];
    int mid = (st + nd) >> 1;
    if (r <= mid)
       return get(1+(idx<<1), st, mid, l, r);
    if (l > mid)
       return get(2+(idx<<1), mid + 1, nd, l, r);
    pair <int, int> temp1 = get(1+(idx<<1), st, mid, l, r),
                    temp2 = get(2+(idx<<1), mid + 1, nd, l, r);
    if (max(temp1.first, temp2.first) > min(temp1.second, temp2.second))
       return {-1, -1};
   return {max(temp1.first, temp2.first), min(temp1.second, temp2.second)};
}

int main() {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &p[i].first, &p[i].second);
        }
        build(0, 0, n - 1);
        int res = -1;
        for (int i = 0; i < n; i++) {
            pair <int, int> temp1 = get(0, 0, n - 1, 0, i - 1),
                            temp2 = get(0, 0, n - 1, i + 1, n - 1);
            if (max(temp1.first, temp2.first) > min(temp1.second, temp2.second))
               res = max(res, 0);
           else
               res = max(res, min(temp1.second, temp2.second) - max(temp1.first, temp2.first));
        }
        printf("%d\n", res);
        return 0;
}
