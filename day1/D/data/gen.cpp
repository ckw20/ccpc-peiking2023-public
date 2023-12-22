#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int p=998244353;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

void add(int &x,int y){x=(x+y>=p)?(x+y-p):x+y;}
int qpow(int x,int y){int ret=1;while(y){if(y&1)ret=1ll*ret*x%p;x=1ll*x*x%p;y>>=1;}return ret;}
ull pw(ull x,int y){
    ull ans=1;
    rep(i,1,y)ans*=x;
    return ans;
}
char command[80];
mt19937_64 rnd(time(0));
void openfile(int x){
    sprintf(command,"%d.in",x);
    freopen(command,"w",stdout);
}
void closefile(int x){
    fclose(stdout);
    sprintf(command,"std.exe < %d.in > %d.ans",x,x);
    system(command);
}

void gen(int x){
    int n=5;if(rnd()%10==0)n=rnd()%4+2;
    int m=50;if(rnd()%10==0)m=rnd()%48+2;
    printf("%d %d\n",n,m);
    int bound;
    int l=rnd()%4;
    if(l==0)bound=19;
    if(l==1)bound=17;
    if(l==2)bound=20;
    if(l==3)bound=13;
    rep(i,1,n)rep(j,1,m){
        int t=rnd()%20;
        if(t>=bound){
            printf("%d%c",rnd()%3," \n"[j==m]);
        }
        else printf("%d%c",3," \n"[j==m]);
    }
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
    rep(i,1,20){
        openfile(i);gen(i);closefile(i);
    }
	return 0;
}
