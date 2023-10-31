#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, tcnt;
    string S;
    cin>>tcnt;
    while (tcnt!=0) {
        cin>>N; cin>>S;
        int open=0, sol=0; 
        for(int i=0; i<S.size();i++)
            if (S[i]=='(') open++;
            else if (open>0) {
                open--;
                sol+=2;
            }
        cout<<sol<<"\n";
        tcnt--;
    }
    return 0;
}
