# include <stdio.h>
# define max 2147483647

int main() {
	int no,color[105][105],smoke[105][105],s[105][105];
	while(scanf("%d",&no)!=EOF) {
		int i,k,j,l,temp;
		for(i=0;i<no;i++) 
			scanf("%d",&color[i][i]);

		for(l=2;l<=no;l++)
			for(i=0;i<no-l+1;i++) {
				j=i+l-1;
				int min = max;
				for(k=i;k<=j-1;k++) {
					temp = smoke[i][k] + smoke[k+1][j] + color[i][k]*color[k+1][j];
					if(temp<min) {
						color[i][j]= (color[i][k] + color[k+1][j])%100;
						min = temp;
						smoke[i][j] = min ;
					}
				}
			}
		int ans;
		printf("%d\n",smoke[0][no-1]);
	}
}