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
    k=10;
    int col=R(4,8);
	int crit=R(1,col);
    w=10000+R(50,200);
	printf("%d %d %d\n",n,k,w);
	for(int i=1;i<=n;++i){
		do{
			int x=R(1,2);
			if(c[i-1]!=crit||x==1)c[i]=crit;
				else c[i]=R(1,col);
		}
		while(c[i]==c[i-1]);
		m[i]=c[i]==crit?R(3,5):k-1;
		if(i%15==0){
			int newcrit;
			do{
				newcrit=R(1,col);
			}
			while(newcrit==crit);
			crit=newcrit;
		}
	}
	p[k]=k*10000;
	for(int i=k+1;i<=k+k-2;++i){
		p[i]=p[i-1]*i/(i-1)/2;
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