#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
map <int,int> mp;
int n,a,b;
int main (int argc,char* argv[]) {
	registerValidation(argc,argv);
	n=inf.readInt(2,100000);
	inf.readChar('\n');
	for (int i=1;i<=n;i++) {
		a=inf.readInt(0,1000000000);
		inf.readSpace();
		b=inf.readInt(0,1000000000);
		inf.readChar('\n');
	}
	inf.readEof();
	return 0;
}
