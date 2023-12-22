#include <bits/stdc++.h>
#include "testlib.h"
signed main (int argc, char *argv[])
{
	registerValidation(argc, argv);
	int n = inf.readInt(1, 300000, "n");
	inf.readSpace();
	int m = inf.readInt(n - 1, n + 1500, "m");
	inf.readEoln();
	std::vector<unsigned> anc(n + 1); std::iota(anc.begin(), anc.end(), 0);
	std::function<int (int)> find = [&] (int x) {return anc[x] == x ? x : anc[x] = find(anc[x]);} ;
	for (int i = 1; i <= m; i++)
	{
		int u = inf.readInt(1, n, "u");
		inf.readSpace();
		int v = inf.readInt(1, n, "v");
		inf.readSpace();
		int w = inf.readInt(1, 1000000000, "w");
		inf.readEoln();
		anc[find(v)] = find(u);
	}
	for (int i = 2; i <= n; i++) ensuref(find(i) == find(1), "The graph is not connected.");
	inf.readEof();
	return 0;
}