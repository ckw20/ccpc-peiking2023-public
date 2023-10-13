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
	int no=io::F();
    char s[111];
    sprintf(s,"%d.in",no);
    freopen(s,"w",stdout);
    n=1;
    k=10;
    int col=4;
    w=351493;
    printf("%d %d %d\n",n,k,w);
    puts("1");
    puts("1");
    for(int i=10;i<=18;++i){
        printf("%d%c",i+1," \n"[i==18]);
    }
	return 0;
}