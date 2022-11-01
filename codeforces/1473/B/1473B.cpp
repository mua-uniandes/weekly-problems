#include <bits/stdc++.h>

using namespace std;

int main() {
  auto mul = [](string s, int k) -> string {
    string res = "";
    while (k--) res += s;
    return res;
  };
  
  int tc;
  cin >> tc;
  while (tc--) {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    int g = __gcd(n, m);
    if (mul(s, m / g) == mul(t, n / g))
      cout << mul(s, m / g) << endl;
    else
      cout << "-1" << endl;
  }
}