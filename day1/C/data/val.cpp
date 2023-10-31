#include<bits/stdc++.h>
#define gc getchar()
#define pc putchar
#define li long long
using namespace std;
inline li read(li l = 0,li r = 1e9){
	li x = 0;
	int y = 0,c = gc;
	while(c < '0' || c > '9'){
		assert(y != '-' && (c == ' ' || c == '\n' || c == '\r' || c == '-'));
		y = c;c = gc;
	} 
	while(c >= '0' && c <= '9') x = x * 10 + c - '0',c = gc;
	assert(c == -1 || c == ' ' || c == '\n' || c == '\r');
	if(y == '-') x *= -1;
	assert(x >= l && x <= r);
	return x;
}
void end_chk(){
	char c;
	do{
		c = gc;
		assert(c == -1 || c == ' ' || c == '\n' || c == '\r');			
	}while(c != -1);
}
int n,k,w,c[200],m[200],p[30];
int main(){
	int tot = 100;
	//tot = read();
	for(int tsd = 1;tsd <= tot;++tsd){
		cerr<<tsd<<":"<<endl;
		char ch[50];
		sprintf(ch,"%d.in",tsd);
		freopen(ch,"r",stdin);
		n = read(1,150);
		k = read(2,10);
		w = read(1,1000000);
		for(int i = 1;i <= n;++i) c[i] = read(1,n);
		for(int i = 1;i < n;++i) assert(c[i] != c[i + 1]);
		for(int i = 1;i <= n;++i) m[i] = read(1,k - 1);
		for(int i = k;i <= k * 2 - 2;++i) p[i] = read(0,1e9);
		for(int i = k;i < k * 2 - 2;++i) assert(p[i + 1] - p[i] < w);
		end_chk();
		fclose(stdin); 
		freopen("con","r",stdin);
		sprintf(ch,"std.exe <%d.in >std.out",tsd);
		system(ch);
		sprintf(ch,"fc %d.ans std.out",tsd);
		system(ch);
		sprintf(ch,"c.exe <%d.in >out.out",tsd);
		system(ch);
		sprintf(ch,"fc %d.ans out.out",tsd);
		system(ch);
		
	} 
	return 0;
}
