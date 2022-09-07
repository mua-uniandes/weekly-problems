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
#include <cmath>

using namespace std;

// aux methods

void printArr(int a[], int sz) {
    for (int i=0; i<sz; i++)
        cout << a[i] << " ";
    cout << "\n";
}

void printVec(vector<int> vec) {
    int sz = vec.size();
    for (int i=0; i<sz; i++)
        cout << vec[i] << "\n";
}

int numDigits(int n) {
    return floor(log10(n) + 1);
}

vector<int> intToVector(int n) {
    vector<int> arr;
    int aux = n;
    while (aux > 0) {
        int c_num = aux%10;
        arr.insert(arr.begin(), c_num);
        aux /= 10;
    }
    return arr;
}

int vectorToInt(vector<int>& vec) {
    vector<int> aux = vec;
    reverse(aux.begin(), aux.end());
    int mult = 1;
    int ret = 0;
    for (auto& it: aux) {
        ret += it*mult;
        mult *= 10;
    }
    return ret;
}

// main

int main() {
    int N, K;
    cin >> N >> K;
    int a[N];
    for (int i=0; i<N; i++)
        cin >> a[i];
    int dp[N];
    for (int i=0; i<N; i++)
        dp[i] = INT_MAX;
    dp[N-1] = 0;
    for(int i=N-2; i>-1; --i) {
        for(int j=i+1, co=0; j<N && co<K; ++j, ++co)
            dp[i] = min(dp[i], dp[j] + abs(a[i]-a[j]));
    }
    cout << dp[0] << endl;
    return 0;
}