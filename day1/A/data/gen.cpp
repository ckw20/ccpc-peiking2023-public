#include<bits/stdc++.h>
using namespace std;

mt19937 rnd(9998);
int genInt(int l, int r){return rnd() % (r - l + 1) + l;}
bool coin(double p){return genInt(0, INT_MAX) < INT_MAX * p;}

void output(vector < int > fa){
	static int CASE_ID = 0; ++CASE_ID;
	ofstream out(to_string(CASE_ID) + ".in");
	int n = fa.size() + 1; out << n << '\n';
	vector < int > id(n); for(int i = 0 ; i < n ; ++i) id[i] = i;
	shuffle(id.begin() + 1, id.end(), rnd);
	for(int i = 0 ; i + 1 < n ; ++i) out << id[i + 1] + 1 << ' ' << id[fa[i]] + 1 << '\n';
	out.close();
	system(("std.exe < " + to_string(CASE_ID) + ".in > " + to_string(CASE_ID) + ".ans").c_str());
}

void chain(bool f){
	int L = f ? 0 : genInt(1, 99996);
	vector<int> fa; for(int i = 1 ; i <= L ; ++i) fa.push_back(i-1);
	fa.push_back(0); for(int i = L + 2 ; i < 1e5 ; ++i) fa.push_back(i-1);
	output(fa);
}

vector<int> merge(vector<vector<int>> son){
	vector<int>res; int presz = 1;
	for(auto t : son){
		for(auto &x: t) x += presz;
		res.push_back(0); res.insert(res.end(), t.begin(), t.end());
		presz += t.size() + 1;
	}
	return res;
}
vector<int> dfs_build(int sz, bool f, int deg){
	if(sz == 1) return {};
	if(sz == 2) return {0};
	if(sz == 3) return f ? vector<int>({0, 0}) : vector<int>({0, 1});
	if(sz == 4) return f ? vector<int>({0, 0, 0}) : vector < int > ({0, 1, 0});
	if(f == 0 && coin(0.01)) return merge({dfs_build(sz - 1 , genInt(0, 1), deg)});
	--sz; int numson = genInt(2, min(sz / 2, deg)) , pson = f ? genInt(2, numson): genInt(0, 1);
	vector < int > psz, nsz;
	for(int i = 0 ; i < pson ; ++i){psz.push_back(1); --sz;}
	for(int i = 0 ; i < numson - pson ; ++i){nsz.push_back(2); sz -= 2;}
	vector<int>pos; for(int i = 0 ; i < nsz.size() ; ++i) pos.push_back(-1 - i);
	if(sz >= 2 && pson){
		psz[0] += 2; sz -= 2; pos.push_back(1);
		for(int j = 1 ; j < pson ; ++j) if(sz >= 2 && coin(0.9)){sz -= 2; psz[j] += 2; pos.push_back(j + 1);}
	}
	while(sz--){int r = pos[genInt(0, pos.size() - 1)]; if(r > 0) ++psz[r - 1]; else ++nsz[-r - 1];}
	vector<vector<int>> son;
	for(auto t : psz) son.push_back(dfs_build(t, 1, deg));
	for(auto t : nsz) son.push_back(dfs_build(t, 0, deg));
	return merge(son);
}

void generate_by_answer(bool f, int deg){
	output(dfs_build(1e5, f, deg));
}

int main(){
	output({}); output({0});
	output({0,0}); output({0,0,1,2});
	chain(0); chain(1);
	generate_by_answer(0, 2);
	generate_by_answer(1, 2);
	generate_by_answer(0, 5);
	generate_by_answer(1, 5);
	generate_by_answer(0, 15);
	generate_by_answer(1, 15);
	generate_by_answer(0, 30);
	generate_by_answer(1, 30);
	return 0;
}