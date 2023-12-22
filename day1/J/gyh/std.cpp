#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,f[502][502],g[502][502];
int main(){
	n=read();
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=n;++j)
			f[i][j]=g[i][j]=read();
	for(re int k=1;k<=n;++k)
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=n;++j)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(re int i=1;i<=n;++i,puts(""))
		for(re int j=1;j<=n;++j){
			re bool o=1;
			for(re int k=1;k<=n;++k)
				if((k^i)&&(k^j)&&f[i][k]+f[k][j]<=g[i][j])o=0;
			if(i==j)o=0;
			printf("%d",o);
		}
}



