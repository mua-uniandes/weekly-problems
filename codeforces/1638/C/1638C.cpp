
#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++) {
        
        int n,k,i;
        
        cin >> n;
        
        i = 0;
        k = 0;
        
        while(i < n) {
            
            int e,j,m;
            cin >> e;
            j = 0;
            m = e-1-i;
            
            while(j < m) {
                
                int r;
                
                cin >> r;
                
                if(r > e) {
                    e = r;
                    m = r-1-i;
                }
                
                j++;
            }
            
            i += j + 1;
            
            k++;
        }
        
        cout << k << endl;
    }
    
    return 0;
}
