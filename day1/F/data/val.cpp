#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;

const int CASES = 15 , MAXN = 3e5 , MAXD = 1500;
int fa[MAXN + 3];
int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}

int main(){
	for(int i = 1 ; i <= CASES ; ++i){
		freopen((to_string(CASES) + ".in").c_str() , "r" , stdin);
		registerValidation();

		int n = inf.readInt(1 , MAXN); inf.readSpace();
		int m = inf.readInt(n - 1 , n + MAXD); inf.readEoln();
		for(int i = 1 ; i <= n ; ++i) fa[i] = i;
		set < pair < int , int > > edgeset;
		for(int i = 1 ; i <= m ; ++i){
			int p = inf.readInt(1 , n); inf.readSpace();
			int q = inf.readInt(1 , n); inf.readSpace();
			int w = inf.readInt(1 , 1e9); inf.readEoln();
			fa[find(p)] = find(q);
			if(p > q) swap(p , q);
			ensuref(edgeset.count(make_pair(p , q)) == 0 , "multiple edges");
			edgeset.insert(make_pair(p , q));
		}
		for(int i = 1 ; i <= n ; ++i)
			ensuref(find(i) == find(n) , "not connected.");

		fclose(stdin); inf.readEof();
		cerr << i << " completed." << endl;
	}
	return 0;
}