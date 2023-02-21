#include <vector>
#include <utility>
#include <iostream>
#include <cassert>
#include <map>
#include <climits>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

#define ll long long
#define REP(i,a) for(int i = 0; i < (a); i++)
#define PB push_back
#define SZ(a) (a).size()
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define fs first
typedef vector<int> vi;
typedef pair<int,int> pii;



int main()
{
    int n;
    cin >> n;
    stack<int> st;
    int curr=1;
    int ans = 0;
    REP(i,2*n){
        string str;
        cin >> str;
        assert(str[0]=='a' || str[0]=='r');
        if(str[0]=='a'){
            int x;
            cin >> x;
            st.push(x);
        }else if(str[0]=='r'){
            if(!st.empty()){
                if(st.top()==curr){ //last thing added is what we need to remove
                    st.pop();
                }else{ //last thing we added is NOT what we need to remove
                    ans++;
                    while(!st.empty()) st.pop(); //clears the stack
                }
            }
            curr++;
        }
    }
    cout << ans << endl;
}