#include <cstdio>
#include <cstring>
using namespace std;
#define MAXNODE 603
#define MOD 1000000007
struct Edge {
	int to, next;
} e[1206];
int f[504][MAXNODE][MAXNODE], vis[504][MAXNODE][MAXNODE];
int head[MAXNODE], tail[MAXNODE], en;
int trie[MAXNODE][27], back[MAXNODE][27], tch[MAXNODE], bch[MAXNODE], tend[MAXNODE], bend[MAXNODE], tid[MAXNODE], bid[MAXNODE], ttot, btot;
char s[MAXNODE];
int dfs(int i, int j, int k){
	if (vis[i][j][k]) return f[i][j][k];
	vis[i][j][k] = 1;
	
	int p, q, u, v;
	for (p = head[j]; p; p = e[p].next) {
		u = e[p].to;
		for (q = tail[k]; q; q = e[q].next) {
			v = e[q].to;
			if (tch[u] == bch[v]) {
				(f[i][j][k] += dfs(i + 1, u, v)) %= MOD;
				if (tend[u]) {
					(f[i][j][k] += dfs(i + 1, 1, v)) %= MOD;
					if (bend[v]) {
						(f[i][j][k] += dfs(i + 1, 1, 1)) %= MOD;
						(f[i][j][k] += dfs(i + 1, u, 1)) %= MOD;
					}
				}
				else if (bend[v]) {
					(f[i][j][k] += dfs(i + 1, u, 1)) %= MOD;
				}
			}
		}
	}
	
	return f[i][j][k];
}
int main(){
	int n, l, i, j, ptr, len, c;
	scanf("%d %d", &n, &l);
	ttot = btot = 1;
	for (i = 1; i <= n; ++i) {
		scanf("%s", s);
		len = strlen(s);
		
		ptr = 1;
		for (j = 0; j < len; ++j) {
			c = s[j] - 'a';
			if (trie[ptr][c] == 0) {
				ptr = trie[ptr][c] = ++ttot;
				tch[ttot] = c;
			}
			else ptr = trie[ptr][c];
			tid[j] = ptr;
		}
		tend[ptr] = 1;
		
		ptr = 1;
		for (j = len - 1; j >= 0; --j) {
			c = s[j] - 'a';
			if (back[ptr][c] == 0) {
				ptr = back[ptr][c] = ++btot;
				bch[btot] = c;
			}
			else ptr = back[ptr][c];
			bid[j] = ptr;
		}
		bend[ptr] = 1;
		
		if (l % 2) {			// odd
			for (j = 0; j < len; ++j) {
				f[(l + 1) / 2][tid[j]][bid[j]] = 1;
			}
		}
		else {					// even
			for (j = 1; j < len; ++j) {
				f[l / 2][tid[j - 1]][bid[j]] = 1;
			}
		}
	}
	if (l % 2 == 0) {						// even: -> m | | (m + 1) <-
		memset(vis[l / 2], 1, sizeof(int) * MAXNODE * MAXNODE);
		f[l / 2][1][1] = 1;
	}
	else memset(vis[(l + 1) / 2], 1, sizeof(int) * MAXNODE * MAXNODE);
	for (i = 1; i <= ttot; ++i) {
		for (c = 0; c < 26; ++c) {
			if (trie[i][c]) {
				e[++en] = (Edge){trie[i][c], head[i]};
				head[i] = en;
			}
		}
	}
	for (i = 1; i <= btot; ++i) {
		for (c = 0; c < 26; ++c) {
			if (back[i][c]) {
				e[++en] = (Edge){back[i][c], tail[i]};
				tail[i] = en;
			}
		}
	}
	
	printf("%d\n", dfs(0, 1, 1));
	return 0;
}