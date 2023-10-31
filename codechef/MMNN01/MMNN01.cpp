#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <chrono>
#define ll long long int
#define maxk 20
#define maxn 1048576
#define p1 101711873
#define p2 104857601
#define p3 111149057
#define g1 78093862
#define g2 79427530
#define g3 85311531
#define g1inv 87893216
#define g2inv 8583183
#define g3inv 62001082
#define inv2p1 50855937
#define inv2p2 52428801
#define inv2p3 55574529
#define pm 1000000007
#define c1 34952567
#define c2 32933262

int rev[maxn];
void prrev(){
	rev[0]=0;
	rev[1]=1;
	for(int lg=2;lg<maxn;lg<<=1){
		for(int i=0;i<lg;++i)
			rev[i]<<=1;
		for(int i=0;i<lg;++i)
			rev[i+lg]=rev[i]^1;
	}
}
int xinv(int x){
	int s=1;
	ll dx=x;
	for(int os=pm-2;os;os>>=1){
		if(os&1)s=(s*dx)%pm;
		dx=(dx*dx)%pm;
	}
	return s;
}

int ma[maxn];
int mb[maxn];
int pr1[maxn];
int pr2[maxn];
int pr3[maxn];
int tra[maxn];
int trb[maxn];
int trc[maxn];
int tinv[maxn];
int cinv[maxn];

void fft(int *a, int *b, int n1, int k, int p, int g){
	int n=1<<k;
	int vk=maxk-k;
	for(int i=0;i<n1;++i)
		b[rev[i]>>vk]=a[i];
	for(int i=n1;i<n;++i)
		b[rev[i]>>vk]=0;
	int gen[k--];
	gen[0]=g;
	for(int i=0;i<k;++i)
		gen[i+1]=(gen[i]*(ll)gen[i])%p;
	for(int len=2;len<=n;len<<=1){
		int gl=gen[k--];
		int lenpola=len/2;
		ll w=1;
		for(int j=0;j<lenpola;++j){
			for(int i=0;i<n;i+=len){
				int u = b[i+j];
				int v = (b[i+j+lenpola]*w)%p;
				u+=v;
				v=u-(v<<1);
				u-=p*(u>=p);
				v+=p*(v<0);
				b[i+j]=u;
				b[i+j+lenpola]=v;
			}
			w=(w*gl)%p;
		}
	}
}

void mul(int *a, int *b, int *c, int n1, int n2, int p, int g, int ginv, int inv2, bool cyc=false){
	int n3=n1+n2-1;
	if(cyc)n3=n1>n2?n1:n2;
	int k,n;
	for(k=0,n=1;n<n3;n<<=1,++k);
	for(int i=k;i<maxk;++i){
		g=(g*(ll)g)%p;
		ginv=(ginv*(ll)ginv)%p;
	}
	fft(a,tra,n1,k,p,g);
	fft(b,trb,n2,k,p,g);
	for(int i=0;i<n;++i)
		trc[i]=(tra[i]*(ll)trb[i])%p;
	fft(trc,c,n,k,p,ginv);
	int invn=inv2;
	for(int i=1;i<k;++i)
		invn=(invn*(ll)inv2)%p;
	for(int i=0;i<n3;++i)
		c[i]=(c[i]*(ll)invn)%p;
}

void mul(int *a, int *b, int *c, int n1, int n2, bool cyc=false){
	for(int i=0;i<n1;++i) ma[i]=a[i]%p1;
	for(int i=0;i<n2;++i) mb[i]=b[i]%p1;
	mul(ma,mb,pr1,n1,n2,p1,g1,g1inv,inv2p1,cyc);
	for(int i=0;i<n1;++i) ma[i]=a[i]%p2;
	for(int i=0;i<n2;++i) mb[i]=b[i]%p2;
	mul(ma,mb,pr2,n1,n2,p2,g2,g2inv,inv2p2,cyc);
	for(int i=0;i<n1;++i) ma[i]=a[i]%p3;
	for(int i=0;i<n2;++i) mb[i]=b[i]%p3;
	mul(ma,mb,pr3,n1,n2,p3,g3,g3inv,inv2p3,cyc);
	int n3=n1+n2-1;
	for(int i=0;i<n3;++i){
		int m=pr1[i];
		int k1=pr2[i]-m;
		k1+=p2*(k1<0);
		k1=(k1*(ll)c1)%p2;
		int k2=(pr3[i]-m-k1*(ll)p1)%p3;
		k2+=p3*(k2<0);
		k2=(k2*(ll)c2)%p3;
		int x=(k2*(ll)p2+k1)%pm;
		c[i]=(x*(ll)p1+m)%pm;
	}
}

void inv(int *a, int *b, int k){
	b[0]=xinv(a[0]);
	b[1]=(b[0]*(ll)(b[0]))%pm;
	b[1]=-(a[1]*(ll)b[1])%pm;
	b[1]+=pm*(b[1]<0);
	int n=2;
	while(n<k)n<<=1;
	for(int l=2;l<n;l<<=1){
		mul(a,b,tinv,2*l,l,true);
		mul(tinv+l,b,trb,l,l);
		for(int i=0;i<l;++i)
			b[i+l]=pm*(trb[i]>0)-trb[i];
	}
}

void div(int *a, int *b, int *c, int n){
	inv(b,cinv,n);
	mul(a,cinv,c,n,n);
}

int a[maxn];
int b[maxn];
int c[maxn];

int resi(int n, int m){
    if(n==1)return 1;
	c[0]=1;
	int mi=xinv(m);
	for(int i=1;i<n;++i){
		c[i]=(c[i-1]*(ll)mi)%pm;
		c[i]=(c[i]*(ll)(m-i))%pm;
	}
	for(int i=0;i<n;++i){
		a[i]=(c[i]*(ll)(i+1))%pm;
		a[i]=(a[i]*(ll)mi)%pm;
	}
	b[0]=0;
	for(int i=1;i<n;++i)
		b[i]=(b[i-1]+a[i-1])%pm;
	for(int i=0;i<n;++i)
		b[i]=(b[i]+c[i])%pm;
	for(int i=n-1;i>0;--i)
		a[i]=pm-a[i-1];
	a[0]=1;
	inv(a,cinv,n);
	mul(b,cinv,c,n,n,true);
	return c[n-1];
}

int n[maxn];
int m[maxn];

int main(){
	prrev();
	
	int t;
	scanf("%d",&t);
	
	for(int i=0;i<t;++i)
		scanf("%d %d",n+i,m+i);
	
	for(int i=0;i<t;++i)
		printf("%d\n",resi(n[i],m[i]));
		
	return 0;
}