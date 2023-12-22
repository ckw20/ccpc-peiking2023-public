/*
start thinking:
BULB:
result of thinking: Pure.

(a, b) 符合要求 iff a -> b 最短路一定经过该边.

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 505
int n, d[maxn][maxn];
bool ans[maxn][maxn];

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &d[i][j]);
      ans[i][j] = (i != j);
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (k != i && k != j && d[i][k] + d[k][j] <= d[i][j]) {
          ans[i][j] = 0;
        }
        chmin(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d", ans[i][j]);
    }
    puts("");
  }
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}
/*
3
0 1 2
1 0 1
2 1 0
*/