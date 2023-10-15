#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;

const int TOTCASE = 85;

int main(){
	for(int i = 1 ; i <= TOTCASE ; ++i){
		freopen((to_string(i) + ".in").c_str() , "r" , stdin);
		registerValidation();
		int N = inf.readInt(1, 333, "N"); inf.readSpace();
		int L = inf.readInt(1, 1000, "L"); inf.readEoln();
		int totlen = 0; set < string > prestr;
		for(int i = 1 ; i <= N ; ++i){
			string str = inf.readToken(); inf.readEoln();
			totlen += str.size(); ensuref(str.size() <= L , "length exceeds L");
			ensuref(prestr.find(str) == prestr.end() , "duplicate string");
			prestr.insert(str);
		}
		ensuref(totlen <= 600 , "tot len exceeds 600");
		inf.readEof();
		fclose(stdin);
		cerr << "Case " << i << " Complete." << endl;
	}
	return 0;
}