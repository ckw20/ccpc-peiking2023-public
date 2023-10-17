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
//const int mo = 1000000007;
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
int n,k,w;
int c[160],m[160],p[30]; 
li f[160][160],g[160][160][12],h[160][160][12][12];
li getf(int l,int r);
li getg(int l,int r,int x);
li geth(int l,int r,int x1,int x2);
li getf(int l,int r){
	//cerr<<"getf: "<<l<<" "<<r<<endl;
	if(l > r) return 0;
	if(f[l][r] >= -1e18l) return f[l][r];
	li ans = -1e18l;
	int i,x1,x2;
	for(i = l;i <= r;++i) if(c[i] != c[l - 1] && c[i] != c[r + 1]){
		ans = max(ans,getf(l,i - 1) + getf(i + 1,r) + p[k] - w * (k - m[i]));
	}
	for(i = l;i + 1 < r;++i) if(c[i] != c[l - 1] && c[i] != c[r + 1]){
		for(x1 = m[i];x1 < k;++x1){
			for(x2 = 0;x2 < k;++x2){
				li val = p[max(x1 + x2,k)] - 1ll * w * max(0,k - x1 - x2);
				ans = max(ans,getf(l,i - 1) + geth(i,r,x1,x2) + val);
			}
		}
	}
	return f[l][r] = ans;
}
li getg(int l,int r,int x){
	//cerr<<"getg: "<<l<<" "<<r<<" "<<x<<endl;
	if(l > r || m[l] > x) return -1e18l;
	if(m[l] == x) return getf(l + 1,r);
	if(g[l][r][x] >= -1e18l) return g[l][r][x];
	li ans = -1e18l;
	for(int i = l + 1;i <= r;++i) if(c[i] == c[l]){
		ans = max(ans,getf(l + 1,i - 1) + getg(i,r,x - m[l]));
	}
	return g[l][r][x] = ans;
}
li geth(int l,int r,int x1,int x2){
	//cerr<<"geth: "<<l<<" "<<r<<" "<<x1<<" "<<x2<<endl;
	if(l > r || m[l] > x1) return -1e18l;
	if(h[l][r][x1][x2] >= -1e18l) return h[l][r][x1][x2];
	li ans = -1e18l;
	if(m[l] == x1){
		for(int i = l + 1;i <= r;++i) if(c[i] == c[l]){
			ans = max(ans,getf(l + 1,i - 1) + getg(i,r,x2));
		}
	}
	else{
		for(int i = l + 1;i <= r;++i) if(c[i] == c[l]){
			ans = max(ans,getg(l,i - 1,x1) + getg(i,r,x2));
		}
	}
	return h[l][r][x1][x2] = ans;
}
int main(){
	srand(time(0));rd();
	//file("");
	int i;
	n = read();k = read();w = read();
	for(i = 1;i <= n;++i) c[i] = read();
	for(i = 1;i <= n;++i) m[i] = read();
	for(i = k;i <= k * 2 - 2;++i) p[i] = read();
	memset(f,0xc0,sizeof(f));
	memset(g,0xc0,sizeof(g));
	memset(h,0xc0,sizeof(h));
	print(getf(1,n));pc('\n');
	//fwrite(bfu,1,bfuu - bfu,stdout);
	//cerr<<clock()<<endl;
	return 0;
}


