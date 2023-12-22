#include<bits/stdc++.h>
//#pragma gcc optimize(3)
#define gc getchar()
//char buf[100000],*buff = buf + 100000;
//#define gc ((buff == buf + 100000 ? (fread(buf,1,100000,stdin),buff = buf) : 0),*(buff++))
#define pc putchar
//char bfu[10000000],*bfuu = bfu;
//#define pc(x) (*(bfuu++) = x)
#define li long long
#define uli unsigned li
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define md int mid = l + r >> 1
#define ls q << 1
#define rs q << 1 | 1
#define ln ls,l,mid
#define rn rs,mid + 1,r
using namespace std;
//const int mo = 998244353;
const int mo = 1000000007;
inline li read(){
	li x = 0;
	int y = 0,c = gc;
	while(c < '0' || c > '9') y = c,c = gc;
	while(c >= '0' && c <= '9') x = x * 10 + c - '0',c = gc;
	return y == '-' ? -x : x;
}
inline void prt(li x){
	if(x >= 10) prt(x / 10);
	pc(x % 10 + '0');
}
inline void print(li x){
	if(x < 0) pc('-'),x = -x;
	prt(x);
}
inline void file(char *s){
	char c[50];
	sprintf(c,"%s.in",s);
	freopen(c,"r",stdin);
	sprintf(c,"%s.out",s);
	freopen(c,"w",stdout);
}
li s1 = 19260817,s2 = 23333333,s3 = 998244853,srd;
inline li rd(){
	return srd = (srd * s1 + s2 + rand()) % s3;
}
int t,k,m,l;
char n[1010];
int f[9010],g[10][9010];
li dp[1010][9010],ans[9010];
inline int work(int x){
	int y = 0;
	while(x){
		y += x % 10;
		x /= 10;
	}
	return y;
}
int main(){
	srand(time(0));rd();
	//file("");
	int i,j,u,v;
	for(i = 1;i <= 9000;++i){
		g[0][i] = i;
		g[1][i] = f[i] = work(i);
	}
	for(i = 2;i <= 5;++i){
		for(j = 1;j <= 9000;++j){
			g[i][j] = g[i - 1][f[j]];
		}
	}
	dp[0][0] = 1;
	for(i = 0;i < 1000;++i){
		for(j = 0;j <= 9 * i;++j){
			dp[i][j] %= mo;
			for(u = 0;u < 10;++u) 
				dp[i + 1][j + u] += dp[i][j];
		}
	}
	for(j = 0;j <= 9000;++j) dp[1000][j] %= mo;
	t = read();
	while(t--){
		scanf("%s",n);
		l = strlen(n);
		k = min(read(),5ll);
		m = read();
		memset(ans,0,sizeof(ans));
		int cnt = 0;
		for(i = 0;i < l;++i){
			int x = n[i] - '0' + (i == l - 1);
			int len = l - i - 1;
			for(u = 0;u <= 9 * len;++u){
				for(j = 0;j < x;++j){
					ans[u + cnt + j] += dp[len][u];
				}
			}
			cnt += x;
		}
		li an = 0;
		for(i = 1;i <= 9000;++i){
			if(g[k - 1][i] == m) an += ans[i]; 
		}
		print(an % mo);pc('\n');
		cerr<<k<<" "<<m<<" "<<an % mo<<endl;
	}
	//fwrite(bfu,1,bfuu - bfu,stdout);
	//cerr<<clock()<<endl;
	return 0;
}


