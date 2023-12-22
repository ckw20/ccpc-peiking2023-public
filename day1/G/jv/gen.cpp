#include<bits/stdc++.h>
#include<random>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int p=998244353;
typedef unsigned long long ull;
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
mt19937_64 rnd(time(0));
typedef unsigned int uint;
const uint M=(1<<20);
char s[80];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
    rep(tms,11,20){
        sprintf(s,"%d.in",tms);
        freopen(s,"w",stdout);
        n=q=200000;
        printf("%d %d\n",n,q);
        rep(i,1,n)printf("%llu ",(2*rnd()+1)%M);puts("");
        while(q--){
            int opt=rnd()%2+1;
            int l=rnd()%10+1,r=n-rnd()%10;if(l>r)swap(l,r);
            if(opt==1){
                ull x=(2*rnd())%M;
                printf("1 %d %d %llu\n",l,r,x);
            }
            if(opt==2){
            printf("2 %d %d\n",l,r);
            }
        }
        fclose(stdout);
        sprintf(s,"std_20 < %d.in > %d.ans",tms,tms);
        system(s);
    }
    
	return 0;
}
