#include<bits/stdc++.h>
using namespace std;
const int N=60,P=998244353,pw[7]={1,3,9,27,81,243,729},dh[3][3]={{0,1,-1},{-1,0,1},{1,-1,0}};
int n,m,a[N][6],b[6],lim,f[2][60][729][7],g[2][60][729][7],ans1,ans2,val[729][6],s[729][6];bool vst[3],ok[729];
inline int nxt(int i){return i==2?0:i+1;}
inline void add(int &x,int y){if((x+=y)>=P)x-=P;}
bool check(int a,int b,int c,int d){
    vst[0]=vst[1]=vst[2]=0,vst[a]=vst[b]=vst[c]=vst[d]=1;
    if(!vst[0]||!vst[1]||!vst[2])return 1;
    return a==d||b==c;
}
void dfs(int x){
    if(x==m+1){
        int M=0,mn=0,mnp=0;
        for(int i=1;i<=m;i++)M+=b[i]*pw[i-1];
        for(int i=1;i<m;i++)if(mn>s[M][i])mn=s[M][i],mnp=i;
        mn=-mn;
        add(f[0][mn][M][m-mnp],mnp),add(g[0][mn][M][m-mnp],1);
        for(int c=mn+1;c<=n+m-2;c++)add(g[0][c][M][0],1);
        return;
    }
    for(int st=0;st<3;st++)if(a[1][x]==3||a[1][x]==st)b[x]=st,dfs(x+1);
}
int main(){
    scanf("%d%d",&n,&m),lim=pw[n+1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)scanf("%d",&a[j][i]);
    swap(n,m);
    bool t=0;
    for(int M=0;M<lim;M++){
        for(int i=0;i<=m;i++)val[M][i]=M/pw[i]%3;
        for(int i=1;i<=m;i++)s[M][i]=s[M][i-1]+dh[val[M][i-1]][val[M][i]];
    }
    dfs(1);
    for(int i=2;i<=n;i++){
        fill(f[t^1][0][0],f[t^1][0][0]+(n+m)*729*7,0),fill(g[t^1][0][0],g[t^1][0][0]+(n+m)*729*7,0);
        for(int st=0;st<3;st++)if(a[i][1]==3||a[i][1]==st){
            for(int c=0;c<=n+m-2;c++)
                for(int M=0,nc,nM,v,np;M<lim;M++){
                    nM=(M%pw[m])*3+st,v=nc=c+dh[M%3][st],np=m;
                    if(v>0){
                        add(f[t^1][nc][nM][0],f[t][c][M][0]),add(g[t^1][nc][nM][0],g[t][c][M][0]);
                        for(int p=1;p<=m;p++)add(f[t^1][nc][nM][p+1],f[t][c][M][p]),add(g[t^1][nc][nM][p+1],g[t][c][M][p]);
                        add(f[t^1][nc][nM][m+1],f[t][c][M][m+1]),add(g[t^1][nc][nM][m+1],g[t][c][M][m+1]);
                    }
                    else if(v==0){
                        add(f[t^1][nc][nM][np],1ll*(i+m-1-np)*g[t][c][M][0]%P),add(g[t^1][nc][nM][np],g[t][c][M][0]);
                        for(int p=1;p<=m;p++)
                            if(np<=p+1)add(f[t^1][nc][nM][p+1],f[t][c][M][p]),add(g[t^1][nc][nM][p+1],g[t][c][M][p]);
                            else add(f[t^1][nc][nM][np],1ll*(i+m-1-np)*g[t][c][M][p]%P),add(g[t^1][nc][nM][np],g[t][c][M][p]);
                        add(f[t^1][nc][nM][m+1],f[t][c][M][m+1]),add(g[t^1][nc][nM][m+1],g[t][c][M][m+1]);
                    }
                }
        }
        t^=1;
        for(int j=2;j<=m;j++){
            fill(f[t^1][0][0],f[t^1][0][0]+(n+m)*729*7,0),fill(g[t^1][0][0],g[t^1][0][0]+(n+m)*729*7,0);
            for(int st=0;st<3;st++)if(a[i][j]==3||a[i][j]==st){
                for(int M=0;M<lim;M++)ok[M]=check(val[M][j-1],val[M][j],val[M][j-2],st);
                for(int c=0;c<=n+m-2;c++)
                    for(int M=0,nM,np,v;M<lim;M++)if(ok[M]){
                        nM=M+(st-val[M][j-1])*pw[j-1],np=m-j+1,v=c+s[nM][j-1];
                        if(v>0){for(int p=0;p<=m+1;p++)add(f[t^1][c][nM][p],f[t][c][M][p]),add(g[t^1][c][nM][p],g[t][c][M][p]);}
                        else if(v==0){
                            for(int p=0;p<=m+1;p++)
                                if(np<=p)add(f[t^1][c][nM][p],f[t][c][M][p]),add(g[t^1][c][nM][p],g[t][c][M][p]);
                                else add(f[t^1][c][nM][np],1ll*(i+m-1-np)*g[t][c][M][p]%P),add(g[t^1][c][nM][np],g[t][c][M][p]);
                        }
                    }
            }
            t^=1;
        }
    }
    for(int c=0;c<=n+m-2;c++)
        for(int M=0;M<lim;M++)
            for(int p=1;p<=m+1;p++)add(ans2,f[t][c][M][p]),add(ans1,g[t][c][M][p]);
    printf("%d %d\n",ans1,ans2);
    return 0;
}