#include <iostream>

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

using namespace std;

string shift(string s, int n) {
    if (n==0)
        return s;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int sz = alphabet.length();
    string st;
    for (int i=0; i<s.length(); i++) {
        char c = s[i];
        int idx = alphabet.rfind(c);
        st += alphabet[(idx+n)%sz];
    }
    return st;
}

int main() {
    int n;
    cin >> n;
    string st;
    cin >> st;
    cout << shift(st,n);
    return 0;
}