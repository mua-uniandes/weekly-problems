#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;

    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        string S;
        cin >> S;
        int skips = 0;
        int j = 0;

        while (j < N) {
            if (j < N - 1) {
                if (S[j] == S[j+1]) {
                    skips += 1;
                    j += 2;
                } else {
                    j += 1;
                }
            } else {
                j += 1;
            }
        }

        int ans = N - skips;
        cout << ans << endl;
    }    

    return 0;
}