#include <bits/stdc++.h>
unsigned binom[20][20];
struct Poly
{
	unsigned a[20];
	Poly () {memset(a, 0, sizeof(a));}
	unsigned & operator [] (int p) {return a[p];}
	friend Poly operator * (Poly &A, Poly &B)
	{
		Poly C;
		for (int i = 0; i < 20; i++) if (A[i])
			for (int j = 0; i + j < 20; j++) C[i + j] += A[i] * B[j];
		return C;
	}
	void trans (int c)
	{
		unsigned p[20] = {0};
		for (int i = p[0] = 1; i < 20; i++) p[i] = p[i - 1] * c;
		for (int i = 0; i < 20; i++) if (a[i]) for (int j = 0; j < i; j++) a[j] += binom[i][j] * a[i] * p[i - j];
	}
};
signed main ()
{
	double t_begin = clock();
	for (int i = 0; i < 20; i++) for (int j = binom[i][0] = 1; j <= i; j++) binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int n, q; std::cin >> n >> q; std::vector<unsigned> a(n), v(n << 2); std::vector<Poly> t(n << 2);
	for (int i = 0; i < n; i++) std::cin >> a[i];
	std::function<void(int, int, int)> build = [&] (int k, int l, int r)
	{
		if (r - l == 1) {t[k][0] = a[l]; t[k][1] = 1; return;}
		build(k << 1, l, (l + r) >> 1); build(k << 1 | 1, (l + r) >> 1, r); t[k] = t[k << 1] * t[k << 1 | 1];
	};
	build(1, 0, n);
	auto modify = [&] (int k, unsigned w) {t[k].trans(w); v[k] += w;} ;
	for (int o, l, r; q--; )
		if (std::cin >> o >> l >> r, o == 1)
		{
			unsigned w; std::cin >> w;
			std::function<void(int, int, int, int, int)> update = [&] (int k, int l, int r, int ql, int qr)
			{
				if (ql <= l and r <= qr) return modify(k, w);
				if (v[k]) modify(k << 1, v[k]), modify(k << 1 | 1, v[k]), v[k] = 0;
				if (ql < (l + r) >> 1) update(k << 1, l, (l + r) >> 1, ql, qr);
				if (qr > (l + r) >> 1) update(k << 1 | 1, (l + r) >> 1, r, ql, qr);
				t[k] = t[k << 1] * t[k << 1 | 1];
			};
			update(1, 0, n, l - 1, r);
		}
		else
		{
			std::function<unsigned(int, int, int, int, int)> query = [&] (int k, int l, int r, int ql, int qr)
			{
				if (ql <= l and r <= qr) return t[k][0];
				if (v[k]) modify(k << 1, v[k]), modify(k << 1 | 1, v[k]), v[k] = 0;
				unsigned ans = 1;
				if (ql < (l + r) >> 1) ans *= query(k << 1, l, (l + r) >> 1, ql, qr);
				if (qr > (l + r) >> 1) ans *= query(k << 1 | 1, (l + r) >> 1, r, ql, qr);
				return ans;
			} ;
			std::cout << (query(1, 0, n, l - 1, r) << 12 >> 12) << '\n';
		}
	double t_end = clock();
	std::cerr << (t_end - t_begin) / CLOCKS_PER_SEC << std::endl;
	return 0;
}