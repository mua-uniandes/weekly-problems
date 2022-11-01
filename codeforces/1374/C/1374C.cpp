#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		int ans = 0;
		int bal = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '(') ++bal;
			else {
				--bal;
				if (bal < 0) {
					bal = 0;
					++ans;
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
