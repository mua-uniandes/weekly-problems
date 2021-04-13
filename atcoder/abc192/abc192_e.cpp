//
//  abc192_e.cpp
//  Problems
//
//  Created by NicolasCardozo on 4/12/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const long long INF = 0x1fffffffffffffff;

long long N, M, K, T, H, W, X, Y;

int main() {
    cin >> N >> M >> X >> Y;
    X--; Y--;
    vector<vector<int>> to(N);
    vector<vector<int>> by(N);
    vector<vector<int>> times(N);
    vector<long long> cost(N, 0x1fffffffffffffff);
    cost[X] = 0;
    for (int i = 0; i < M; i++) {
        int A, B, T, K;
        cin >> A >> B >> T >> K;
        A--; B--;
        to[A].push_back(B);
        times[A].push_back(T);
        by[A].push_back(K);
        to[B].push_back(A);
        times[B].push_back(T);
        by[B].push_back(K);
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> PQ;
    PQ.emplace(0, X);
    while (!PQ.empty()) {
        long long c, cn;
        tie(c, cn) = PQ.top();
        PQ.pop();
        if (cost[cn] < c) continue;
        for (int i = 0; i < to[cn].size(); i++) {
            long long st = c / by[cn][i];
            st += !!(c%by[cn][i]);
            st *= by[cn][i];
            if (cost[to[cn][i]] > st + times[cn][i]) {
                cost[to[cn][i]] = st + times[cn][i];
                PQ.emplace(cost[to[cn][i]], to[cn][i]);
            }
        }
    }
    long long ans = cost[Y];
    if (ans == INF) ans = -1;
    cout << ans << endl;
}
