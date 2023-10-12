#include <cstdio>
#include <cstring>
using namespace std;
#define BASE 37
#define BLOCK_SIZE 80
unsigned int hs[603][756], ht[756], w[60003][27];
char s[603][60003], t[60003];
int main(){
	int n, m, q, k, i, j, cnt, ans, ptr, l, r, mid;
	unsigned long long p, hsp, htp;
	scanf("%d %d %d %d", &n, &q, &m, &k);
	p = 1;
	for (i = 0; i < m; ++i, p *= BASE) {
		for (j = 0; j < 26; ++j) {
			w[i][j] = (i + j) % (BASE - 1) + 1;
			w[i][j] *= p;
		}
	}
	for (i = 1; i <= n; ++i) {
		scanf("%s", s[i]);
		for (j = 0; j < m; ++j) {
			hs[i][j / BLOCK_SIZE] ^= w[j][s[i][j] - 'a'];
		}
	}
	
	for (i = 1; i <= q; ++i) {
		scanf("%s", t);
		memset(ht, 0, sizeof(ht));
		for (j = 0; j < m; ++j) {
			ht[j / BLOCK_SIZE] ^= w[j][t[j] - 'a'];
		}
		ans = 0;
		for (j = 1; j <= n; ++j) {
			ptr = cnt = 0;
			for (l = 0; l <= (m - 1) / BLOCK_SIZE; ++l) {
				if (hs[j][l] != ht[l]) {
					r = ((l + 1) * BLOCK_SIZE > m ? m : (l + 1) * BLOCK_SIZE);
					for (ptr = l * BLOCK_SIZE; ptr < r; ++ptr) {
						if (s[j][ptr] != t[ptr]) {
							++cnt;
							if (cnt > k) break;
						}
					}
					if (cnt > k) break;
				}
			}
			if (cnt <= k) ++ans;
			// else fprintf(stderr, "%d[%s] %d[%s]\n", i, t, j, s[j]);
		}
		printf("%d\n", ans);
	}
	return 0;
}