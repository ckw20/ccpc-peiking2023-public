#include <cstdio>
using namespace std;
#define BASE 37
unsigned long long hs[603][60003], ht[60003], w[60003][27];
char s[603][60003], t[60003];
int main(){
	int n, m, q, k, i, j, cnt, ans, ptr, l, r, mid;
	unsigned long long p, hsp, htp;
	scanf("%d %d %d %d", &n, &q, &m, &k);
	p = 1;
	for (i = 1; i <= m; ++i, p *= BASE) {
		for (j = 0; j < 26; ++j) {
			w[i][j] = (i + j) % (BASE - 1) + 1;
			w[i][j] *= p;
		}
	}
	for (i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
		hs[i][0] = 0;
		for (j = 1; j <= m; ++j) {
			hs[i][j] = hs[i][j - 1] + w[j][s[i][j] - 'a'];
		}
	}
	
	for (i = 1; i <= q; ++i) {
		scanf("%s", t + 1);
		ht[0] = 0;
		for (j = 1; j <= m; ++j) {
			ht[j] = ht[j - 1] + w[j][t[j] - 'a'];
		}
		ans = 0;
		for (j = 1; j <= n; ++j) {
			ptr = 0;
			for (cnt = 0; cnt < k && ptr < m; ++cnt) {
				if (hs[j][m] - (hsp = hs[j][ptr]) == ht[m] - (htp = ht[ptr])) {
					break;
				}
				l = ptr;
				r = m;
				while (r - l > 1) {
					mid = l + r >> 1;
					if (hs[j][mid] - hsp == ht[mid] - htp) l = mid;
					else r = mid;
				}
				ptr = l + 1;
				// if (i == 1 && j == 29) fprintf(stderr, "%d %d %d\n", j, cnt, ptr);
			}
			// if (i == 1) fprintf(stderr, "%d %d %d %d\n", i, j, cnt, ptr);
			if (cnt < k) ++ ans;
			else if (cnt == k && hs[j][m] - hs[j][ptr] == ht[m] - ht[ptr]) ++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}