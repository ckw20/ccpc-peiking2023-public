#include "testlib_modified.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	int T = inf.readInt(1, 5, "T"); inf.eoln();
	while (T--) {
		string s = inf.readStrictString("[0-9]*", 1, 1001, ' ', "s");
		inf.readSpace();
		quitif(s[0] == '0', _fail, "s[0] must not be 0.\n");
		if (s.length() == 1001u) {
			quitif(s[0] != '1', _fail, "s[0] must be 1 when length of s is 1001.\n");
			for (int i = 1; i < (int)s.length(); i++)
				quitif(s[i] != '0', _fail, "s[i] for i > 0 must be 0 when length of s is 1001.\n");
		}
		int k = inf.readInt(1, 1000000000); inf.readSpace();
		int m = inf.readInt(1, 1000000000); inf.eoln();
		}
	inf.readEof();
	return 0;
}