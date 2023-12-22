#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
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
const int N=100010;char s[N];

ull bitpre[70],bitsuf[70];
int bitcnt[(1<<16)+10],bitlowbit[(1<<16)+10];
inline int prelude_bitinf()
{
	//bitpre,bitsuf,bitcnt,bitlowbit
	rep(i,0,62) bitpre[i]=(1ull<<(i+1))-1;bitpre[63]=~0ull;
	rep(i,1,63) bitsuf[i]=(~0ull)^bitpre[i-1];bitsuf[0]=~0ull;
	rep(i,0,(1<<16)-1) rep(j,0,15) bitcnt[i]+=((i>>j)&1);
	rep(i,1,(1<<16)-1) rep(j,0,15) if((i>>j)&1) { bitlowbit[i]=j;break; }
	return 0;
}

class My_bitset{
	private:
		ull *a;int N,n;
	public:
		My_bitset() { a=NULL,N=0,n=0; }
		My_bitset(int _N,ull init_val=0) { N=_N,n=(N-1)/64+1,a=new ull[n],memset(a,0,sizeof(ull)*n),a[0]=init_val; }
		My_bitset(const My_bitset &b) { N=b.N,n=b.n,a=new ull[n],memcpy(a,b.a,sizeof(ull)*n); }
		~My_bitset() { if(a!=NULL) delete a; }
		inline My_bitset& operator=(const My_bitset &b) { N=b.N,n=b.n,a=new ull[n];return memcpy(a,b.a,sizeof(ull)*n),*this; }
		inline My_bitset operator&(const My_bitset &b)const{ My_bitset c(*this);rep(i,0,n-1) c.a[i]&=b.a[i];return c; }
		inline My_bitset& operator&=(const My_bitset &b) { rep(i,0,n-1) a[i]&=b.a[i];return *this; }
		inline My_bitset operator|(const My_bitset &b)const{ My_bitset c(*this);rep(i,0,n-1) c.a[i]|=b.a[i];return c; }
		inline My_bitset& operator|=(const My_bitset &b) { rep(i,0,n-1) a[i]|=b.a[i];return *this; }
		inline My_bitset operator^(const My_bitset &b)const{ My_bitset c(*this);rep(i,0,n-1) c.a[i]^=b.a[i];return c; }
		inline My_bitset& operator^=(const My_bitset &b) { rep(i,0,n-1) a[i]^=b.a[i];return *this; }
		inline My_bitset operator~()const{ My_bitset c(*this);rep(i,0,n-1) c.a[i]=~c.a[i];c.a[n-1]&=bitpre[(N-1)&63];return c; }
		inline bool operator==(const My_bitset &b)const{ rep(i,0,n-1) if(a[i]^b.a[i]) return false;return true; }
		inline bool operator!=(const My_bitset &b)const{ rep(i,0,n-1) if(a[i]^b.a[i]) return true;return false; }
		inline int test(int x)const{ return (a[x>>6]>>(x&63))&1ll; }
		inline void set() { rep(i,0,n-1) a[i]=~0ull; }
		inline void set(int x) { a[x>>6]|=1ull<<(x&63); }
		inline void set(int l,int r)
		{
			int x=l>>6,y=r>>6,s=l&63,t=r&63;
			if(x==y) { a[x]|=(s?bitpre[s-1]:0)^bitpre[t];return; }
			rep(i,x+1,y-1) a[i]=~0ull;a[x]|=bitsuf[s],a[y]|=bitpre[t];
		}
		inline void reset() { rep(i,0,n-1) a[i]=0; }
		inline void reset(int x) { a[x>>6]&=(~0ull)^(1ull<<(x&63)); }
		inline void reset(int l,int r)
		{
			int x=l>>6,y=r>>6,s=l&63,t=r&63;
			if(x==y) { a[x]&=(s?bitpre[s-1]:0)|(t<63?bitsuf[t+1]:0);return; }
			rep(i,x+1,y-1) a[i]=0ull;a[x]&=(s?bitpre[s-1]:0),a[y]&=(t<63?bitsuf[t+1]:0);
		}
		inline void flip(int x) { a[x>>6]^=1ull<<(x&63); }
		inline int count()const
		{
			int ans=0;rep(i,0,n-1) ans+=
				bitcnt[a[i]&bitpre[15]]+bitcnt[(a[i]>>16)&bitpre[15]]+
				bitcnt[(a[i]>>32)&bitpre[15]]+bitcnt[a[i]>>48];
			return ans;
		}
		inline bool any(int p=0)const{ rep(i,p>>6,n-1) if(a[i]) return true;return false; }
		inline bool all(int p=0)const{ rep(i,p>>6,n-1) if(a[i]<(~0ull)) return false;return true; }
		inline bool none(int p=0)const{rep(i,p>>6,n-1) if(a[i]) return false;return true; }
		inline int lowbit(int p=0)const
		{
			ull b=0;
			rep(i,p>>6,n-1) if(a[i])
			{
				if((b=(a[i]&bitpre[15]))) return (i<<6)+bitlowbit[b];
				if((b=((a[i]>>16)&bitpre[15]))) return (i<<6)+16+bitlowbit[b];
				if((b=((a[i]>>32)&bitpre[15]))) return (i<<6)+32+bitlowbit[b];
				if((b=(a[i]>>48))) return (i<<6)+48+bitlowbit[b];
			}
			return -1;
		}
		inline My_bitset collect(int l,int r)const
		{
			int x=l>>6,y=r>>6,s=l&63,t=r&63;
			My_bitset c(r-l+1);
			rep(i,x+1,y)
				c.a[i-x-1]=(a[i-1]>>s)|(s?((a[i]&bitpre[s-1])<<(64-s)):0ull);
			// debug(l)sp,debug(r)sp,debug(x)sp,debug(y)sp,debug(s)sp,debug(t)sp,debug(c.n)ln;
			if(t<s) c.a[y-x-1]&=bitpre[64-s+t];
			else c.a[y-x]=(a[y]&bitpre[t])>>s;
			return c;
		}
		inline My_bitset collect(int _n)const { return collect(0,_n-1); }
		inline void show()const { rep(i,0,N-1) cerr<<test(i);cerr ln; }
		inline friend ostream& operator<<(ostream &os,const My_bitset &b) { rep(i,0,b.N-1) os<<b.test(i);return os; }
};


int main()
{
	prelude_bitinf();
	int n=inn();scanf("%s",s);
	My_bitset S(n),Q(n),b,cur;
	rep(i,0,n-1) if(s[i]=='1') S.set(i);
	rep(i,0,n-1) if(s[i]=='?') Q.set(i);
	b=(~Q)&S;
	// debug(S)sp,debug(Q)sp,debug(b)ln;
	rep(k,1,n)
	{
		// debug(k)ln;
		cur=b.collect(k);
		int ans=cur.count(),l,r;
		// debug(0)sp,debug(0)sp,debug(k-1)sp,debug(cur)sp,debug(cur.count())ln;
		rep(i,1,(n-1)/k)
			l=i*k,r=min((i+1)*k-1,n-1),cur=b.collect(l,r)|(Q.collect(l,r)&cur),ans+=cur.count();
			// debug(i)sp,debug(l)sp,debug(r)sp,debug(cur)sp,debug(cur.count())ln;
		printf("%d\n",ans);
	}
	cerr<<clock()<<endl;
	return 0;
}
