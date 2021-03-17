#include <iostream>
//data structures
#include <array>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <typeinfo>
//other
#include <bits/stdc++.h>

using namespace std;

int pretty_nums(int& l, int& r) {
    int pn = 0;
    for (int i=l; i<=r; i++) {
        if (i%10 == 2 || i%10 ==3  || i%10 == 9)
            pn++;
    }
    return pn;
}

int main() {
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        int l,r;
        cin >> l >> r;
        cout << pretty_nums(l,r) << "\n";
    }
    return 0;
}