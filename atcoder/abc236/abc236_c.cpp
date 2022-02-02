#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    string S[N];
    unordered_set<string> T;
    for (int i = 0; i < N; ++i)
        cin >> S[i];
    for (int i = 0; i < M; ++i) {
        string tmp;
        cin >> tmp;
        T.insert(tmp);
    }
    for (int i = 0; i < N; ++i) {
        if (T.count(S[i]))  cout << "Yes";
        else    cout << "No";
        cout << "\n";
    }
}