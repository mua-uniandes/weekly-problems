
#include <iostream>

using namespace std;

void newSpotlights(bool act, int idx, int * lst, int * t)
{
    if(!act && *lst != -1) 
        (*t)++;
    
    if(act) {
        *t += idx - *lst - 1;
        *lst = idx;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    int t = 0;
    int lsts[m];
    for(int j=0; j<m; j++) lsts[j] = -1;
    
    for(int i=0; i<n; i++) {
        
        int lst_row = -1;  // Last position for a 1 in current row
        for(int j=0; j<m; j++) {
            
            int act;
            cin >> act;
            newSpotlights(act==1, j, &lst_row, &t);  // row
            newSpotlights(act==1, i, &lsts[j], &t);  // column
        }
    }
    
    cout << t;

    return 0;
}
