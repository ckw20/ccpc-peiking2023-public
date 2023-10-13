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
int main(int argc, char** argv){
	if(argc<4){
		fputs("no k col",stderr);
		exit(1);
	}
	int no=atoi(argv[1]);
    char s[111];
    sprintf(s,"%d.in",no);
    freopen(s,"w",stdout);
    n=150;
    k=atoi(argv[2]);
    int col=atoi(argv[3]);
    w=R(1,1000000);
	printf("%d %d %d\n",n,k,w);
	for(int i=1;i<=n;++i){
		do{
			c[i]=R(1,col);
		}
		while(c[i]==c[i-1]);
		m[i]=R(1,k-1);
	}
	p[k-1]=w*k;
	for(int i=k;i<=k+k-2;++i){
		p[i]=p[i-1]+R(-w+1,w-1);
	}
	for(int i=1;i<=n;++i){
		printf("%d%c",c[i]," \n"[i==n]);
	}
	for(int i=1;i<=n;++i){
		printf("%d%c",m[i]," \n"[i==n]);
	}
	for(int i=k;i<=k+k-2;++i){
		printf("%d%c",p[i]," \n"[i==k+k-2]);
	}
	return 0;
}