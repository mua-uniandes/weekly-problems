#include "bits/stdc++.h"
using namespace std;

const int nax = 2e5 + 5;
vector<pair<int,int>> intervals[nax];
const long long INF = 1e18L + 5;

// add to the prefix
// give the min of everything

struct S {
    long long small, lazy;
    void merge(const S& a, const S& b) {
        small = min(a.small, b.small);
        assert(lazy == 0);
    }
    void add(ll x) {
        small += x;
        lazy += x;
    }
};
vector<S> tree;

const int TYPE_ADD = 1, TYPE_MIN = 2;
void rec(int id, int low, int high, int q_low, int q_high, int type, long long& x) {
    if(high < q_low || q_high < low) {
        return;
    }
    if(q_low <= low && high <= q_high) {
        if(type == TYPE_ADD) 
            tree[id].add(x);
        else if(type == TYPE_MIN) 
            x = min(x, tree[id].small);
		else 
            assert(false);
		return;
    }
    for(int b : {2 * id, 2 * id + 1}) 
        tree[b].add(tree[id].lazy);
    tree[id].lazy = 0;
    
    int last_left = (low + high) / 2;
    rec(2 * id, low, last_left, q_low, q_high, type, x);
    rec(2 * id + 1, last_left + 1, high, q_low, q_high, type, x);
    
    tree[id].merge(tree[2*id], tree[2*id+1]);
}
        

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    long long sum_of_scores = 0;
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        intervals[b].emplace_back(a, c);
        sum_of_scores += c;
    }
    long long answer = 0;
    
    int base = 1;
    while(base <= n + 1) {
        base *= 2;
    }
    tree.resize(2 * base, {INF, 0});
    
    long long whatever = 0 - INF;
    rec(1, 0, base - 1, 0, 0, TYPE_ADD, whatever);
    for(int i = 1; i <= n + 1; ++i) {
        for(pair<int,int> p : intervals[i-1]) {
            whatever = p.second;
            rec(1, 0, base - 1, 0, p.first - 1, TYPE_ADD, whatever);
        }
        long long best = INF;
        rec(1, 0, base - 1, 0, base - 1, TYPE_MIN, best);
        if(i == n + 1) 
            answer = best;
        whatever = best - INF;
        rec(1, 0, base - 1, i, i, TYPE_ADD, whatever);
    }
    printf("%lld\n", sum_of_scores - answer);
}