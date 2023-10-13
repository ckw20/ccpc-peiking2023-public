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
std::random_device device;
std::mt19937_64 gen(device());
int R(int l, int r){
    return std::uniform_int_distribution<int>(l,r)(gen);
}
int m[1111],c[1111],p[1111];
int n,k,w;
int main(){
	int no=6;
    char s[111];
    sprintf(s,"%d.in",no);
    freopen(s,"w",stdout);
    n=150;
    k=10;
    int col=4;
    w=1;
    printf("%d %d %d\n",n,k,w);
    for(int i=1;i<=n;++i){
		do{
			c[i]=i;
		}
		while(c[i]==c[i-1]);
		printf("%d%c",c[i]," \n"[i==n]);
	}
	for(int i=1;i<=n;++i){
		printf("%d%c",1," \n"[i==n]);
	}
    for(int i=10;i<=18;++i){
        printf("%d%c",1000000000," \n"[i==18]);
    }
	return 0;
}