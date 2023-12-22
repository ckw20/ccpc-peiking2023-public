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
char s[100010];
int main()
{
	rep(id,1,23)
	{
		debug(id)sp;string ids;for(int x=id;x;x/=10) ids+=char('0'+x%10);
		reverse(ids.begin(),ids.end()),freopen((ids+".in").c_str(),"r",stdin);
		// int sid=id;
		int n=inn();R(n,1,100000);
		scanf("%s",s+1);
		rep(i,1,n) assert(s[i]=='0'||s[i]=='1'||s[i]=='?');
		fclose(stdin);
		debug(id)ln;
	}
	return 0;
}
