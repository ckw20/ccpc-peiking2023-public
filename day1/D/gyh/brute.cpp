#include<bits/stdc++.h>
#define re register
#define ui unsigned int
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,q,k,ans,p[60002];
char s[602][60002];
ui hsh[602],H;
inline int ask(re int x,re int y){
	if(hsh[x]==H)return 1;
	re int ss=0;
	for(re int i=1;i<=m&&ss<=k;++i)ss+=s[x][i]!=s[y][i];
	return ss<=k;
}
int main(){
	n=read(),q=read(),m=read(),k=read();
	mt19937 rnd(114514);
	for(re int i=1;i<=m;++i)p[i]=rnd()%i+1;
	for(re int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(re int i=1;i<=n;++i)for(re int j=1;j<=m;++j)swap(s[i][j],s[i][p[j]]);
	for(re int i=1;i<=n;++i)for(re int j=1;j<=m;++j)hsh[i]=131*hsh[i]+s[i][j];
	while(q--){
		scanf("%s",s[n+1]+1),ans=H=0;
		for(re int i=1;i<=m;++i)swap(s[n+1][i],s[n+1][p[i]]),H=H*131+s[n+1][i];
		for(re int i=1;i<=n;++i)ans+=ask(i,n+1);
		printf("%d\n",ans);
	} 
}



