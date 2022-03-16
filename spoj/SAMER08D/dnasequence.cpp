#include <cstdio>
#include<string.h>
#include<stdlib.h>
#define N 1009
#include<algorithm>
using namespace std;

int main() {
	char s[N], t[N];
    int lcs[N][N], cont[N][N]; //lcs is answer matrix and cont is matrix for storing common segment length
     int k,z;
     scanf("%d", &k);
    while( k ){
        scanf("%s %s", s, t);
        int l1=strlen(s),i,j;
        int l2=strlen(t);
        cont[0][0] = 0;
        for(i=0;i<N;i++) lcs[i][0] = lcs[0][i] = 0;
        for(i=1;i<=l1;i++)
            for(int j = 1; j <= l2; ++j) {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                if(s[i-1]==t[j-1])
                cont[i][j]=cont[i-1][j-1]+1;
                else 
                cont[i][j]=0;
                //update lcs matrix if segment size is greater than or equal to k
                if(cont[i][j] >= k)
                for(z= k; z <= cont[i][j]; z++)
                    lcs[i][j] = max(lcs[i][j], lcs[i - z][j - z] + z);//update
            }
        printf("%d\n",lcs[l1][l2]);
        scanf("%d",&k);
    }
    return 0;
}