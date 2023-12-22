
#include "testlib.h"

int main(int argc, char* argv[])
{
	registerValidation(argc, argv);	
	int n = inf.readInt(2, 5); inf.readSpace();
	int m = inf.readInt(2, 50); inf.readEoln();
	while (n--) {
		inf.readInts(m, 0, 3);
		inf.readEoln();
	}
	inf.readEof();
	return 0;
}
