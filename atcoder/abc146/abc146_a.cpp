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

int days(string& day) {
    if (day == "SUN")
        return 7;
    else {
        unordered_map<string, int> mp;
        mp["MON"] = 1;
        mp["TUE"] = 2;
        mp["WED"] = 3;
        mp["THU"] = 4;
        mp["FRI"] = 5;
        mp["SAT"] = 6;
        return 7 - mp[day];
    }
}

int main() {
    string inp;
    cin >> inp;
    cout << days(inp) << "\n";
    return 0;
}