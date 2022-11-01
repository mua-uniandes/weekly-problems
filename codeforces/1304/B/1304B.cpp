#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
string s[MAX_N];

int main() {
	set<string> dict;
	int n, m, i;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> s[i];
		dict.insert(s[i]);
	}
	vector<string> left, right;
	string mid;
	for (i = 0; i < n; i++) {
		string t = s[i];
		reverse(t.begin(), t.end());
		if (t == s[i])
			mid = t;
		else if (dict.find(t) != dict.end()) {
			left.push_back(s[i]);
			right.push_back(t);
			dict.erase(s[i]);
			dict.erase(t);
		}
	}
	cout << left.size() * m * 2 + mid.size() << endl;
	for (string x : left)
		cout << x;
	cout << mid;
	reverse(right.begin(), right.end());
	for (string x : right)
		cout << x;
	cout << endl;
}