#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair < int , int >
#define st first
#define nd second
const int _ = 3e5 + 7;
int N , M, indeg[_] , outdeg[_], ans = 1e18; bool imp[_] , del[_];
vector < pii > shortcut[_] , ed[_] , red[_]; vector < int > impset;

void dfs(int x , int rt,int cursum){
	if(indeg[x] == 0 || outdeg[x] == 0) return;
	for(auto t : ed[x])
		if(!imp[t.st]) dfs(t.st, rt, cursum + t.nd);
		else if(rt == t.st) ans = min(ans, cursum + t.nd);
		else shortcut[rt].push_back(pii(t.st, t.nd + cursum));
}

void solve(int st){
	static int dst[_]; for(auto t : impset) dst[t] = 1e18;
	dst[st] = 0; priority_queue < pii > q; q.push(pii(0, st));
	while(!q.empty()){
		int w = -q.top().st, p = q.top().nd; q.pop();
		if(dst[p] != w) continue;
		for(auto t : shortcut[p]){
			if(t.st == st) ans = min(ans , dst[p] + t.nd);
			else if(dst[t.st] > dst[p] + t.nd)
				q.push(pii(-(dst[t.st] = dst[p] + t.nd), t.st));
		}
	}
}

signed main(){
	ios::sync_with_stdio(0); cin >> N >> M;
	for(int i = 1 ; i <= M ; ++i){
		int u , v , w; cin >> u >> v >> w; ++indeg[v]; ++outdeg[u];
		ed[u].push_back(pii(v , w)); red[v].push_back(pii(u , w));
	}

	// Delete zero degree
	queue < int > q; int cntdel = 0;
	for(int i = 1 ; i <= N ; ++i) if(indeg[i] == 0 || outdeg[i] == 0) q.push(i);
	while(!q.empty()){
		int t = q.front(); q.pop(); if(del[t]) continue;
		del[t] = 1; ++cntdel;
		if(indeg[t] == 0){outdeg[t] = 0; for(auto p : ed[t]) if(--indeg[p.first] == 0) q.push(p.first);}
		else{indeg[t] = 0; for(auto p : red[t]) if(--outdeg[p.first] == 0) q.push(p.first);}
		ed[t].clear(); red[t].clear();
	}
	//cerr << cntdel << endl;
	if(cntdel == N){cout << "-1" << endl; return 0;}
	
	// Delete one degree
	for(int i = 1 ; i <= N ; ++i) if(imp[i] = (indeg[i] > 1 || outdeg[i] > 1)) impset.push_back(i);
	//cerr << impset.size() << endl;

	if(impset.empty()){
		long long sum = 0; 
		for(int i = 1 ; i <= N ; ++i) if(!del[i]) for(auto t : ed[i]) if(!del[t.first]) sum += t.second;
		cout << sum; return 0;
	}
	for(auto t : impset) dfs(t, t, 0);
	for(auto t : impset) solve(t);
	cout << (ans == 1e18 ? -1 : ans) << endl; return 0;
}