include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
int x[MAXN],y[MAXN],a[MAXN],degree[MAXN];
int n,m;
void work()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		degree[i]=0;
		cin>>a[i];
	}
	for (int i=1;i<=m;i++)
	{
		cin>>x[i]>>y[i];
		degree[x[i]]++;
		degree[y[i]]++;
	}
	int ans=INT_MAX;
	if (m%2==0)
		ans=0;
	for (int i=1;i<=n;i++)
		if (degree[i]%2==1)
			ans=min(ans,a[i]);
	for (int i=1;i<=m;i++)
		if (degree[x[i]]%2==0 && degree[y[i]]%2==0)
			ans=min(ans,a[x[i]]+a[y[i]]);
	cout<<ans<<endl;
}

int main()
{
	int casenum=1;
	cin>>casenum;
	for (int testcase=1;testcase<=casenum;testcase++)
		work();
	return 0;
}