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

int g1(int n) {
    vector<int> vec = intToVector(n);
    sort(vec.begin(), vec.end(), greater<int>());
    return vectorToInt(vec);
}

int g2(int n) {
    vector<int> vec = intToVector(n);
    sort(vec.begin(), vec.end());
    return vectorToInt(vec);
}

int main() {
    int N,K;
    cin >> N >> K;
    int a = N;
    for (int i=0; i<K; i++) {
        int v_g1 = g1(a);
        int v_g2 = g2(a);
        a = v_g1 - v_g2;
    }
    cout << a << "\n";
    return 0;
}