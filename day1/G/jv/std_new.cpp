#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int p=998244353;
typedef unsigned int ull;
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

void add(int &x,int y){x=(x+y>=p)?(x+y-p):x+y;}
int qpow(int x,int y){int ret=1;while(y){if(y&1)ret=1ll*ret*x%p;x=1ll*x*x%p;y>>=1;}return ret;}
int n,q;
const int N=2e5+5,d=20;
ull a[N],tag[4*N],c[100][100];
void precalc(){
    //in this case we only compute modulo x^20
    rep(i,0,d)c[i][0]=1;
    rep(i,1,d)rep(j,1,i)c[i][j]=c[i-1][j]+c[i-1][j-1];
}
struct poly{
    ull coef[d];
}s[N*4];
poly mul(poly x,poly y){
    ull coef[d];memset(coef,0,sizeof(coef));
    rep(i,0,d-1)rep(j,0,d-i-1)coef[i+j]+=x.coef[i]*y.coef[j];
    poly z;
    rep(i,0,d-1)z.coef[i]=coef[i];
    return z;
}
void translate(poly &x,ull y){//y should be even
    //printf("dbg translate %llu\n",y);
    poly z;memset(z.coef,0,sizeof(z.coef));
    ull curr[d];
    curr[0]=1;
    rep(i,1,d-1)curr[i]=curr[i-1]*y;
    rep(t,0,d-1){
        //x^t->(x+y)^t
        rep(j,0,t)z.coef[j]+=c[t][j]*x.coef[t]*curr[t-j];//,printf("wtf %d %d %d %d %d\n",t,j,c[t][j],x.coef[t],curr[t-j]);
    }
    //rep(t,0,65)printf("%llu ",z.coef[t]);puts("");
    x=z;
}

void dbg(int p,int l,int r){
    printf("dbg %d %d %d\n",p,l,r);
    rep(i,0,65)printf("%llu ",s[p].coef[i]);puts("");
}
void merge(int p){
    s[p]=mul(s[2*p],s[2*p+1]);
}
void pushdown(int p){
    translate(s[2*p],tag[p]);
    translate(s[2*p+1],tag[p]);
    tag[2*p]+=tag[p];
    tag[2*p+1]+=tag[p];
    tag[p]=0;
}
void build(int p,int l,int r){
    if(l==r){
        s[p].coef[0]=a[l];
        s[p].coef[1]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    merge(p);
}
void add(int p,int l,int r,int nl,int nr,ull x){
    if(nl<=l&&r<=nr){
        //dbg(p,l,r);
        translate(s[p],x);
        tag[p]+=x;
        //dbg(p,l,r);
        return;
    }
    int mid=(l+r)>>1;
    pushdown(p);
    if(nl<=mid)add(2*p,l,mid,nl,nr,x);
    if(mid+1<=nr)add(2*p+1,mid+1,r,nl,nr,x);
    merge(p);
}
ull query(int p,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr)return s[p].coef[0];
    ull ans=1;
    int mid=(l+r)>>1;
    pushdown(p);
    if(ql<=mid)ans*=query(2*p,l,mid,ql,qr);
    if(mid+1<=qr)ans*=query(2*p+1,mid+1,r,ql,qr);
    return ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
    precalc();
    cin>>n>>q;
    rep(i,1,n)cin>>a[i];
    build(1,1,n);
    //dbg(1,1,n);
    while(q--){
        int opt;cin>>opt;
        if(opt==1){
            int l,r; ull x;cin>>l>>r>>x;
            add(1,1,n,l,r,x);
        }
        if(opt==2){
            int l,r;cin>>l>>r;
            ull ans=query(1,1,n,l,r);
            ans%=(1<<20);
            printf("%u\n",ans);
        }
    }
	return 0;
}