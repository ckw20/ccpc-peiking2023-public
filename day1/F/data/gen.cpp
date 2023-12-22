#include<bits/stdc++.h>
using namespace std;

mt19937 rnd(9998);
const int MAXN = 3e5 , MAXM = 1500 , MAXW = 1e9;
int genInt(int l, int r){return rnd() % (r - l + 1) + l;}
bool coin(double p){return genInt(0, INT_MAX) < INT_MAX * p;}
template < typename T >
T & sample(vector < T > &vec){return vec[genInt(0, vec.size() - 1)];}

struct Edge{int u, v, w; void swap(){std::swap(u, v);}};
int n = genInt(MAXN / 2, MAXN), m; vector < Edge > ed;

void output(){
	static int CASE_ID = 0; ++CASE_ID;
	ofstream out(to_string(CASE_ID) + ".in");
	out << n << ' ' << m << '\n'; 
	cerr << n << ' ' << m << ' ' << ed.size() << endl;
	assert(ed.size() == m);
	vector < int > id(n); for(int i = 0 ; i < n ; ++i) id[i] = i;
	shuffle(ed.begin(), ed.end(), rnd);
	for(auto e : ed) out << id[e.u - 1] + 1 << ' ' << id[e.v - 1] + 1 << ' ' << e.w << '\n';
	out.close();
	cerr << CASE_ID << " generated." << endl;
	system(("std.exe < " + to_string(CASE_ID) + ".in > " + to_string(CASE_ID) + ".ans").c_str());
	n = genInt(MAXN / 2, MAXN); ed.clear();
}

void cycle(int cyclen, bool addone, bool randomswap){
	m = n; vector < int > pre;
	if(addone) pre = {1}; else for(int i = 1 ; i <= cyclen ; ++i) if(coin(5.0 / cyclen)) pre.push_back(i);
	for(int i = 1 ; i <= cyclen ; ++i){
		ed.push_back((Edge){i, i % cyclen + 1 , genInt(1, MAXW)});
		if(randomswap && coin(0.5)) ed.back().swap();
	}
	for(int i = cyclen + 1 ; i <= n ; ++i){
		int p = sample(pre); ed.push_back((Edge){p, i, genInt(1, MAXW)});
		if(coin(0.5)) ed.back().swap();
		if(coin(0.9)) pre.push_back(i);
	}
	output();
}

void chain(){
	m = n - 1; for(int i = 1 ; i < n ; ++i) ed.push_back((Edge){i, i + 1, genInt(1, MAXW)});
	output();
}

void tree(){
	m = n - 1; 
	for(int i = 2 ; i <= n ; ++i){
		ed.push_back((Edge){i, genInt(1, i - 1), genInt(1, MAXW)});
		if(coin(0.5)) ed.back().swap();
	}
	output();
}

void dag(){
	m = n + genInt(MAXM / 2, MAXM); 
	for(int i = 2 ; i <= n ; ++i) ed.push_back((Edge){i, genInt(1, i - 1), genInt(1, MAXW)});
	for(int i = n ; i <= m ; ++i){
		int p = genInt(1, n), q = genInt(1, n);
		while(p == q) p = genInt(1, n), q = genInt(1, n);
		ed.push_back((Edge){max(p, q), min(p, q), genInt(1, MAXW)});
	}
	output();
}

void add_chain(vector<int>pot, int weight_max = MAXW){
	for(int i = 1 ; i < pot.size() ; ++i) ed.push_back((Edge){pot[i - 1] , pot[i] , genInt(1, weight_max)});
}

void hack_brute_shrink(){
	m = n + MAXM;
	for(int i = 3 ; i < MAXM + 1 + 3 ; ++i){
		ed.push_back((Edge){i, 1, genInt(1, MAXW)});
		ed.push_back((Edge){2, i, genInt(1, MAXW)});
	}
	vector < int > pot = {1}; for(int i = MAXM + 1 + 3 ; i <= n ; ++i) pot.push_back(i);
	pot.push_back(2); add_chain(pot);
	output();
}

void random(int mn = 3, int mx = MAXM){
	int sz = genInt(mn , mx), additional_edge = genInt(MAXM / 2 , MAXM);
	m = n + additional_edge;
	vector < vector < int > > pot(additional_edge + sz);
	for(int i = sz + 1 ; i <= n ; ++i) sample(pot).push_back(i);
	for(int i = 1 ; i <= sz ; ++i){
		vector < int > cur{i}; cur.insert(cur.end(), pot.back().begin(), pot.back().end()); pot.pop_back();
		cur.push_back(i % sz + 1); add_chain(cur, MAXW / sz);
	}
	for(int i = 1 ; i <= additional_edge ; ++i){
		int p = genInt(1, sz), q = genInt(1, sz) , weight = MAXW / sz * ((q + sz - p - 1) % sz + 1);
		vector < int > cur{p}; cur.insert(cur.end(), pot.back().begin(), pot.back().end()); pot.pop_back();
		cur.push_back(q); add_chain(cur, weight);
	}
	output();
}

void full(){
	n = MAXN; m = n + MAXM;
	vector < vector < int > > pot(MAXM * 3);
	for(int i = MAXM + 1 ; i <= n ; ++i) sample(pot).push_back(i);
	for(int i = 1 ; i <= MAXM ; ++i){
		vector < int > cur{i}; cur.insert(cur.end(), pot.back().begin(), pot.back().end()); pot.pop_back();
		cur.push_back(i % MAXM + 1); add_chain(cur);
		cur = {i}; cur.insert(cur.end(), pot.back().begin(), pot.back().end()); pot.pop_back();
		cur.insert(cur.end(), pot.back().begin(), pot.back().end()); pot.pop_back();
		cur.push_back((i % MAXM + 1) % MAXM + 1); add_chain(cur);
	}
	output();
}

int main(){
	ios::sync_with_stdio(0);
	chain(); tree(); dag();
	cycle(n, 0, 0); cycle(genInt(5, 2000), 1, 0); cycle(genInt(1, n), 1, 0); cycle(genInt(1, n), 0, 1);
	full(); random(3, 3); random(3, 50); random(3, 200); random(3, 1000); random(500, MAXM); random(); random();

	return 0;
}