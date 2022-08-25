#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<int> p(n);
		for (int i = 0; i < m; ++i) {
			int pos;
			cin >> pos;
			p[pos - 1] = 1;
		}
		while (true) {
			bool ok = false;
			for (int i = 0; i < n; ++i) {
				if (p[i] && a[i] > a[i + 1]) {
					ok = true;
					swap(a[i], a[i + 1]);
				}
			}
			if (!ok) break;
		}
		bool ok = true;
		for (int i = 0; i < n - 1; ++i)
			ok &= a[i] <= a[i + 1];
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	
	return 0;
}