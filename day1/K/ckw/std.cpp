#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define lint long long
using namespace std;
const int N = 1010, M = N * 9, K = 5, mod = 1000000007;
char s[N]; int f[N][M], trs[M][K + 1]; lint cnt[M], nxt[M];
inline void P(int &x) { x >= mod ? x -= mod : 0; }
inline void prelude (int n, int k) {
	int m = n * 9;
	rep (i, 1, m) trs[i][0] = i, trs[i][1] = trs[i / 10][1] + (i % 10);
	rep (j, 1, k) rep (i, 1, m) trs[i][j] = trs[trs[i][1]][j - 1];
	f[0][0] = 1;
	rep (i, 0, n - 1) {
		int *now = f[i], tmp;
		memset(nxt, 0, sizeof(lint) * (9 * (i + 1) + 1));
		rep (j, 0, 9 * i) if ((tmp = now[j])) nxt[j] += tmp, nxt[j + 10] -= tmp;
		rep (j, 1, 9 * (i + 1)) nxt[j] += nxt[j - 1];
		rep (j, 0, 9 * (i + 1)) f[i + 1][j] = int(nxt[j] % mod);
	}
}
int main() {
	prelude(1000, K);
	int T, n, k, m; scanf("%d", &T);
	while (T--) {
		scanf("%s%d%d", s + 1, &k, &m), n = (int)strlen(s + 1);
		int ps = 0; lint ans = 0;
		memset(cnt, 0, sizeof(lint) * (9 * n + 1));
		rep (i, 1, n) {
			int c = s[i] - '0', tmp, *now = f[n - i];
			rep (t, 0, 9 * (n - i)) if ((tmp = now[t]))
				cnt[t + ps] += tmp, cnt[t + ps + c] -= tmp;
			ps += c;
		}
		rep (i, 1, 9 * n) cnt[i] += cnt[i - 1]; cnt[ps] += 1;
		rep (i, 0, 9 * n) if(trs[i][min(k - 1, K)] == m) ans += cnt[i];
		printf("%d\n", ans % mod);
	}
	return 0;
}