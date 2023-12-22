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
const int N=2e5+5;
ull a[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    rep(i,1,n)cin>>a[i];
    while(q--){
        int opt;cin>>opt;
        if(opt==1){
            int l,r; ull x;cin>>l>>r>>x;
            rep(i,l,r)a[i]+=x;
        }
        if(opt==2){
            int l,r;cin>>l>>r;
            ull ans=1;
            rep(i,l,r)ans*=a[i];
            ans%=(1<<20);
            printf("%u\n",ans);
        }
    }
	return 0;
}
