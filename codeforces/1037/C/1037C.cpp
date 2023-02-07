# include <iostream>
# include <algorithm>

using namespace std;

int main() {
  int n, a;
  int mx = 0, cnt = 0;
  cin >> n;
  cin >> a;
  int t_a = a;
  for (int i = 1; i < n; i++) {
    cin>>a;
    if(a <= (2 * t_a)){
      cnt++;
      mx = max(mx, cnt);
    } else {
      cnt = 0;
    }
    t_a = a;
  }
  cout<< mx + 1 << "\n";
  return 0;
}