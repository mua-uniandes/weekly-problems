#include <bits/stdc++.h>

using namespace std;

int main() {
	int x; cin >> x >> x;
	
	string s1; 
	cin >> s1;
	string s2; 
	cin >> s2;
	string s3 = { s1.front(), s2.front(), s1.back(), s2.back() };
	cout << (s3 == "<v>^" || s3 == ">^<V" ? "YES" : "NO");
}