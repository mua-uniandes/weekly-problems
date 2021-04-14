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

void printArr(int a[], int sz) {
    for (int i=0; i<sz; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main() {
    string st;
    cin >> st;
    bool hard = true;
    for (int i=0; i<st.size() && hard; i++) {
        char c = st[i];
        if (i%2 == 0) { // Odd
            if (isupper(c))
                hard = false;
        } else { // Oddn't
            if (islower(c))
                hard = false;
        }
    }
    string out = hard ? "Yes" : "No";
    cout << out << "\n";
    return 0;
}