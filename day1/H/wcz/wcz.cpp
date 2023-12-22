#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100010;
struct P {int v,bel,id;P (int a=0,int b=0,int c=0) {v=a,bel=b,id=c;}} p[2*N];
int n,flg,a[N],b[N],cnt[N],vis[3];
ll sum,ans,nw;
bool cmp (P a,P b) {return a.v>b.v;}
int main () {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d%d",&a[i],&b[i]);sum+=a[i]+b[i];
		p[2*i-1]=P(a[i],i,1),p[2*i]=P(b[i],i,2);
	}
	sort(p+1,p+2*n+1,cmp);
	for (int i=1;i<=n;i++) {
		nw+=p[i].v;vis[p[i].id]++;
		if (++cnt[p[i].bel]==2) {flg=1;}
	}
	if (!vis[1]||!vis[2]||flg) {printf("%lld\n",nw*2-sum);return 0;}
	for (int i=1;i<=n;i++) {
		if (vis[1]==1&&a[i]>b[i]) {ans=max(ans,nw-a[i]+b[i]);}
		if (vis[2]==1&&a[i]<b[i]) {ans=max(ans,nw-b[i]+a[i]);}
		if (a[i]>b[i]) {
			if (a[i]!=p[n].v) {ans=max(ans,nw-p[n].v+b[i]);}
			else {ans=max(ans,nw-p[n-1].v+b[i]);}
		} else {
			if (b[i]!=p[n].v) {ans=max(ans,nw-p[n].v+a[i]);}
			else {ans=max(ans,nw-p[n-1].v+a[i]);}
		}
	}
	printf("%lld\n",ans*2-sum);
	return 0;
}
