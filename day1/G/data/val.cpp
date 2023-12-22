#include "testlib.h"
#include <bits/stdc++.h>
signed main (int argc, char *argv[])
{
	registerValidation(argc, argv);
	int n = inf.readInt(1, 200000, "n");
	inf.readSpace();
	int q = inf.readInt(1, 200000, "q");
	inf.readEoln();
	std::vector<unsigned> a(n + 1);
	for (int i = 1; i <= n; i++)
		a[i] = inf.readUnsignedLong(1, (1u << 20) - 1, "a[" + std::to_string(i) + "]"),
		inf.readSpace(),
		ensuref(a[i] & 1, "a[%d] is not an odd number.", i);
	inf.readEoln();
	for (int i = 1; i <= q; i++)
	{
		int o = inf.readInt(1, 2, "opt");
		inf.readSpace();
		int l = inf.readInt(1, n, "l");
		inf.readSpace();
		int r = inf.readInt(l, n, "r");
		if (o == 1)
		{
			inf.readSpace();
			unsigned x = inf.readUnsignedLong(0, (1u << 20) - 1, "x");
			ensuref(!(x & 1), "x is not an even number.");
		}
		inf.readEoln();
	}
	inf.readEof();
	return 0;
}