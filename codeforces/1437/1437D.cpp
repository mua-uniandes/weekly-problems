#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

const int INF = int(1e9);

int n;
vector<int> a;

inline bool read() {
	if(!(cin >> n))
		return false;
	a.resize(n);
	for(int i = 0; i < n; i++) 
		cin >> a[i];
	return true;
}

inline void solve() {
	vector<int> h(n, INF);
	h[0] = 0;
	int lst = 0;
	for(int i = 1; i < n; i++) {
		if (i - 1 > 0 && a[i - 1] > a[i])
			lst++;
		h[i] = h[lst] + 1;
	}
	cout << h[n - 1] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int tc; 
    cin >> tc;
	while(tc--) {
		read();
		solve();		
	}
	return 0;
}