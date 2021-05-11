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
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int N;
        cin >> N;
        int a[N];
        for (int j = 0; j < N; j++) {
            cin >> a[j];
        }
        // sol
        vector<int> vec = {0};
        int sum = a[0];
        for (int j = 1; j < N; j++) {
            if (a[j]%2 == 0) {
                vec.clear();
                vec.push_back(j);
                sum = a[j];
                break;
            } else {
                if ((sum+a[j])%2 == 0) {
                    vec.push_back(j);
                    sum += a[j];
                }
            }
        }
        if (sum%2==0) {
            cout << vec.size() << endl;
            for (int j = 0; j < vec.size(); j++) {
                if (j == (vec.size()-1)) {
                    cout << (vec[j]+1) << endl;
                } else {
                    cout << (vec[j]+1) << " ";
                }
            }
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}