#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 7; vector < int > nxt[_]; int N;
int dfs(int x, int p){
	if(nxt[x].size() == 1) return 1;
	int cnt = 0; for(auto t : nxt[x]) if(t != p) cnt += dfs(t , x);
	return cnt >= 2;
}

int main(){
	cin >> N; for(int i = 2 ; i <= N ; ++i){int p, q; cin >> p >> q; nxt[p].push_back(q); nxt[q].push_back(p);}
	cout << (dfs(1 , 0) ? "You win, temporarily." : "Wasted.");
	return 0;
}