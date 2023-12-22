/*
start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include "testlib.h"
#include <bits/stdc++.h>

#define maxn 505
int n, a[maxn][maxn];

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  n = inf.readInt(1, 500, "n");
  inf.readEoln();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = inf.readInt(0, int(1e6), "a_ij");
      if (j < n)
        inf.readSpace();
      else {
        // inf.readSpace();
        inf.readEoln();
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ensuref(a[i][j] == a[j][i], "a_ij != a_ji");
    }
  }
  for (int i = 1; i <= n; i++) {
    ensuref(a[i][i] == 0, "a_ii != 0");
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        ensuref(a[i][j], "a_ij == 0");
      }
    }
  }
  inf.readEof();
  return 0;
}
