//
//  570C.cpp
//  Problems
//
//  Created by NicolasCardozo on 3/04/22.
//  Copyright © 2022 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;
 
const long long dd = 3e5 + 7;
 
string s;
char t = '.';
int n, m;
 
int num, group;
bool ok[dd];
 
int main(){
    cin >> n >> m >> s;
    for(int i=0; i<n; i++){
        if(s[i] == t){
            num++;
            if(i == 0 || s[i - 1] != t)
                group++;
            ok[i + 1] = 1;
        }
    }
    for(int i=0; i<m; i++){
        int d;
        char c;
        scanf("%d %c", &d, &c);
        bool a = ok[d], b = c == t;
        if(a != b){
            if(a)
                num--;
            else
                num++;
            if(ok[d - 1] && ok[d + 1] && !b)
                group++;
            if(ok[d - 1] && ok[d + 1] && b)
                group--;
            if(!ok[d - 1] && !ok[d + 1] && !b)
                group--;
            if(!ok[d - 1] && !ok[d + 1] && b)
                group++;
        }
        ok[d] = b;
        printf("%d\n", num - group);
    }
    return 0;
}
