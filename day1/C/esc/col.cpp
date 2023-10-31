#include<bits/stdc++.h>
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define cmax(a,b) (a<(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
namespace io{
	int F(){
		int n=0,F=0;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=1:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
		return F?-n:n;
	}
	long long G(){
		long long n=0,F=0;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=1:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
		return F?-n:n;
	}
}
int k,w;
int m[1111],p[1111],c[1111];
long long f[166][166];
long long g1[166][166][11];
long long g2[166][166][11][11];
long long F(int l, int r);
long long G1(int l, int r, int p1);
long long G2(int l, int r, int p1, int p2);
long long F(int l, int r){
    if(l>r)return 0;
    if(f[l][r]>-0x3f3f3f3f3f3f3f40ll){
        return f[l][r];
    }
    auto &res=f[l][r];
    res=-0x3f3f3f3f3f3f3f3fll;
    for(int i=l;i<=r;++i){
        if(1){
            for(int p1=1;p1<k;++p1){
                for(int p2=1;p2<k;++p2){
                    long long tmp=G2(l,i,p1,p2)+F(i+1,r)-1ll*w*dmax(0,k-p1-p2)+p[dmax(k,p1+p2)];
                    cmax(res,tmp);
                }
                long long tmp=F(l,i-1)-1ll*w*(k-m[i])+p[k]+F(i+1,r);
                cmax(res,tmp);
            }
        }
    }
    return res;
}
long long G1(int l, int r, int p1){
    if(g1[l][r][p1]>-0x3f3f3f3f3f3f3f40ll){
        return g1[l][r][p1];
    }
    auto &res=g1[l][r][p1];
    res=-0x3f3f3f3f3f3f3f3fll;
    if(c[r]==c[l-1]||p1<m[r])return res;
    if(p1==m[r]){
        long long tmp=F(l,r-1);
        cmax(res,tmp);
    }
    else{
        for(int i=l;i<r;++i){
            if(c[i]==c[r]){
                long long tmp=G1(l,i,p1-m[r])+F(i+1,r-1);
                cmax(res,tmp);
            }
        }
    }
    return res;
}
long long G2(int l, int r, int p1, int p2){
    if(g2[l][r][p1][p2]>-0x3f3f3f3f3f3f3f40ll){
        return g2[l][r][p1][p2];
    }
    auto &res=g2[l][r][p1][p2];
    res=-0x3f3f3f3f3f3f3f3fll;
    if(c[r]==c[l-1]||p2<m[r])return res;
    if(p2==m[r]){
        for(int i=l;i<r;++i){
            if(c[i]==c[r]){
                long long tmp=G1(l,i,p1)+F(i+1,r-1);
                cmax(res,tmp);
            }
        }
    }
    else{
        for(int i=l;i<r;++i){
            if(c[i]==c[r]){
                long long tmp=G2(l,i,p1,p2-m[r])+F(i+1,r-1);
                cmax(res,tmp);
            }
        }
    }
    return res;
}
int main(){
	int n=io::F();
    k=io::F();
    w=io::F();
    for(int i=1;i<=n;++i){
        c[i]=io::F();
    }
    for(int i=1;i<=n;++i){
        m[i]=io::F();
    }
    for(int i=k;i<=k+k-2;++i){
        p[i]=io::F();
    }
    memset(f,192,sizeof(f));
    memset(g1,192,sizeof(g1));
    memset(g2,192,sizeof(g2));
    printf("%lld\n",F(1,n));
	return 0;
}