# include <bits/stdc++.h>
using namespace std;

int main() {
  long n;
  cin >> n;
  string s;
  while (n--) {
    cin >> s;
    long c(0);
    if (s[0] == s[1]) {
      c ++;
      s[1] = 'X';
    }
    for (long p = 2; p < s.size(); p++) {
      if (s[p - 1] == s[p]) s[p] = 'X', ++c;
      else if (s[p - 2] == s[p]) s[p] = 'X', ++c;
    }
    cout << c << "\n";
  }
  return 0;
}