//  C - King's Task
// Carlos Peña

#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int per1[2*n];
    int per2[2*n];
    int init[2*n];

    for (int i=0; i<2*n; i++) {
        cin >> per1[i];
        per2[i] = per1[i];
        init[i] = per1[i];
    }

    int c1 = 0;
    bool solved = false;
    int lastop = 0;
    while (!solved) {
        solved = true;
        for (int i=0; i<2*n-1;i++) {
            if (per1[i]+1 != per1[i+1]) {
                solved = false;
                break;
            }
        }
        if (solved) break;
        if (!solved) {
            c1++;
            if (lastop == 0) {
                for (int j=0; j<2*n; j+=2) {
                    int actual = per1[j];
                    per1[j] = per1[j+1];
                    per1[j+1] = actual;
                }
                lastop = 1;
            } else {
                for (int j=0; j<n; j+=1) {
                    int actual = per1[j];
                    per1[j] = per1[j+n];
                    per1[j+n] = actual;
                }
                lastop = 0;
            }
        }
        bool notPossible = true;
        for (int i=0; i<2*n; i++) {
            if (per1[i] != init[i]) {
                notPossible = false;
                break;
            }
        }
        if (notPossible) {
            solved = true;
            c1 = -1;
        }
    }

    int c2 = 0;
    solved = false;
    lastop = 1;
    while (!solved) {
        solved = true;
        for (int i=0; i<2*n-1;i++) {
            if (per2[i]+1 != per2[i+1]) {
                solved = false;
                break;
            }
        }
        if (solved) break;
        if (!solved) {
            c2++;
            if (lastop == 0) {
                for (int j=0; j<2*n; j+=2) {
                    int actual = per2[j];
                    per2[j] = per2[j+1];
                    per2[j+1] = actual;
                }
                lastop = 1;
            } else {
                for (int j=0; j<n; j+=1) {
                    int actual = per2[j];
                    per2[j] = per2[j+n];
                    per2[j+n] = actual;
                }
                lastop = 0;
            }
        }
        bool notPossible = true;
        for (int i=0; i<2*n; i++) {
            if (per2[i] != init[i]) {
                notPossible = false;
                break;
            }
        }
        if (notPossible) {
            solved = true;
            c2 = -1;
        }
    }

    if ((c1 == -1) && (c2 == -1)) {
        cout << "-1\n";
    } else {
        if (c1 == -1) {
            cout << c2 << "\n";
        } else if (c2 == -1) {
            cout << c1 << "\n";
        } else {
            cout << min(c1,c2) << "\n";
        }
    }
    return 0;
}
