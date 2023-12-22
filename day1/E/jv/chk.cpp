#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second


void chkmin(int &x,int y){
    x=min(x,y);
}
const int N=2005;
int dp[N][N],n,m,p[N],q[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    rep(i,1,n)cin>>p[i];
    rep(i,1,m)cin>>q[i];
    reverse(p+1,p+n+1);
    reverse(q+1,q+m+1);
    rep(i,0,n)rep(j,0,m)dp[i][j]=1e6;
    dp[0][0]=0;
    //dp[i][j]:the first i bits of p, the first j bits of q, matching each other, the least amount of 1 to append
    rep(i,0,n)rep(j,0,m){
        chkmin(dp[i+1][j],dp[i][j]+1);
        chkmin(dp[i][j+1],dp[i][j]+1);
        if((p[i+1]==q[j+1])||(p[i+1]==1)||(q[j+1]==1))chkmin(dp[i+1][j+1],dp[i][j]);
        //printf("dbg %d %d %d\n",i,j,dp[i][j]);
    }
    int ans=1e6;
    rep(i,0,m)chkmin(ans,dp[n][i]);
    rep(j,0,n)chkmin(ans,dp[j][m]);
    printf("%d\n",ans);
	return 0;
}