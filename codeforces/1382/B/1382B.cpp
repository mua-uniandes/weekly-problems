# include <bits/stdc++.h>

using namespace std;

void solution() {
  int n;
  cin >> n;
  vector <int> v(n);
  int ones = 0;

  for (auto &x : v) {
    cin >> x;
    if(x == 1) ones ++;
  }

  if (n == 1 || ones == 0) {
    cout << "First" << "\n";
    return;
  }

  if (ones == n) {
    if (n & 1) cout << "First" << "\n";
    else cout << "Second" << "\n";
    return;
  }

  bool first = false;
  for (int i = 0; i < n; i++){
    if(v[i] == 1) first ^= 1;
    else break;
  }
  
  if (first) cout << "Second" << "\n";
  else cout << "First" << "\n";
}

int main(){
  int a;
  cin >> a;
  for (int i = 0; i < a; i ++) solution();
  return 0;
}
