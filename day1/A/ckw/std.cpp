#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,v) rep(i,0,(int)v.size()-1)
#define lint long long
#define ull unsigned lint
#define db long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define gc getchar()
#define debug(x) cerr<<#x<<"="<<x
#define sp <<" "
#define ln <<endl
using namespace std;
typedef pair<int,int> pii;
typedef set<int>::iterator sit;
inline int inn()
{
	int x,ch;while((ch=gc)<'0'||ch>'9');
	x=ch^'0';while((ch=gc)>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^'0');return x;
}
const int N=200010;vector<int> g[N];
int dfs(int x,int fa=0,int cnt=0)
{
	for(int i=0,y;i<(int)g[x].size();i++)
		if((y=g[x][i])!=fa) cnt+=dfs(y,x);
	return ((int)g[x].size()==1)||cnt>=2;
}
int main()
{
	int n=inn(),u,v;rep(i,1,n-1) u=inn(),v=inn(),g[u].pb(v),g[v].pb(u);
	printf((n>1&&dfs(1))?"You win, temporarily.\n":"Wasted.\n");
	return 0;
}
