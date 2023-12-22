#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,v) rep(i,0,(int)v.size()-1)
#define lint long long
#define uint unsigned int
#define ull unsigned lint
#define db double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define gc getchar()
#define lb(x) ((x)&-(x))
#define debug(x) cerr<<#x<<"="<<x
#define sp <<" "
#define ln <<endl
using namespace std;
typedef pair<int,int> pii;
typedef set<int>::iterator sit;
inline int getn(int a,int b) { return (rand()*32767+rand())%(b-a+1)+a; }
int inn() { int x;scanf("%d",&x);return x; }
inline void R(int x,int l,int r) { assert(x>=l&&x<=r); }
int fa[100010];
inline int findf(int x) { if(x==fa[x]) return x;return fa[x]=findf(fa[x]); }
inline int con(int x,int y) { x=findf(x),y=findf(y),assert(x!=y),fa[x]=y;return 0; }
int main()
{
	rep(id,1,14)
	{
		debug(id)sp;string ids;for(int x=id;x;x/=10) ids+=char('0'+x%10);
		reverse(ids.begin(),ids.end()),freopen((ids+".in").c_str(),"r",stdin);
//		int sid=id;
		int n=inn(),u,v;R(n,1,100000);rep(i,1,n) fa[i]=i;
		rep(i,1,n-1) u=inn(),v=inn(),R(u,1,n),R(v,1,n),con(u,v);
		fclose(stdin);
		debug(id)ln;
	}
	return 0;
}
