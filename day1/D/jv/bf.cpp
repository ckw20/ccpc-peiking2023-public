#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int mod=998244353;
typedef long long ll;
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

void add(int &x,int y){x=(x+y>=mod)?(x+y-mod):x+y;}
int qpow(int x,int y){int ret=1;while(y){if(y&1)ret=1ll*ret*x%mod;x=1ll*x*x%mod;y>>=1;}return ret;}

int n,m,a[6][55],b[6][55],c[6][55],d[6][55],flg[6][55],curr,ans,cnt;
int dii[4]={1,0,-1,0};
int dij[4]={0,1,0,-1};
void solve(){
    rep(i,1,n)rep(j,1,m)b[i][j]=d[i][j];
    //printf("solve:\n");
    //rep(i,1,n){
    //    rep(j,1,m)printf("%d ",b[i][j]);puts("");
    //}
    curr=0;
    bool final=0;
    rep(tms,1,n+m+3){
        bool unchanged=1;
        rep(i,1,n)rep(j,1,m){
            bool flg=0;
            rep(u,0,3){
                int dx=dii[u],dy=dij[u];
                if(b[i+dx][j+dy]==(b[i][j]+2)%3)flg=1;
            }
            ::flg[i][j]=flg;
            unchanged&=(!flg);
        }
        rep(i,1,n)rep(j,1,m)c[i][j]=flg[i][j]?(b[i][j]+2)%3:b[i][j];
        if(b[1][1]!=c[1][1])curr=tms;
        if(unchanged){
            ans+=curr;cnt++;
            //printf("get=%d\n",curr);
            return;
        }
        rep(i,1,n)rep(j,1,m)b[i][j]=c[i][j];
    }
}
void dfs(int i,int j){
    if(j==m+1){
        solve();return;
    }
    if(a[i][j]<3){
        d[i][j]=a[i][j];
        if(i==n)dfs(1,j+1);
        else dfs(i+1,j);
    }
    else{
        rep(k,0,2){
            d[i][j]=k;
            if(i==n)dfs(1,j+1);
            else dfs(i+1,j);
        }
    }
}
int main(){
    //freopen("1.txt","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    rep(i,0,n+1)rep(j,0,m+1)b[i][j]=3;
    rep(i,1,n)rep(j,1,m)cin>>a[i][j];
    dfs(1,1);
    printf("%d %d\n",cnt,ans);
	return 0;
}
