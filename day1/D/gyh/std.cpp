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
int n,m,q,k,ans;
char s[602][60002];
ui hsh[602][60002],pw[60002];
inline ui ask(re int x,re int l,re int r){return hsh[x][r]-hsh[x][l-1]*pw[r-l+1];}
inline int ask(re int x,re int y){
	re int pos=0;
	for(re int i=0;i<=k;++i){
		re int l=pos+1,r=m,o=pos;
		while(l<=r){
			re int mid=l+r>>1;
			if(ask(x,pos+1,mid)==ask(y,pos+1,mid))o=mid,l=mid+1;
			else r=mid-1;
		}
		if(o==m)return 1;
		pos=o+1;
	}return 0;
}
int main(){
	n=read(),q=read(),m=read(),k=read();
	for(re int i=pw[0]=1;i<=m;++i)pw[i]=pw[i-1]*131;
	for(re int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=m;++j)
			hsh[i][j]=hsh[i][j-1]*131+s[i][j];
	while(q--){
		scanf("%s",s[n+1]+1),ans=0;
		for(re int i=1;i<=m;++i)hsh[n+1][i]=hsh[n+1][i-1]*131+s[n+1][i];
		for(re int i=1;i<=n;++i)ans+=ask(i,n+1);
		printf("%d\n",ans);
	} 
}



