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
constexpr int B = 9;
signed main ()
{
	double t_begin = clock();
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	for (int i = 0; i < 20; i++) for (int j = binom[i][0] = 1; j <= i; j++) binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int n, q; std::cin >> n >> q;
	std::vector<Poly> a(n), t((n >> B) + 1); std::vector<unsigned> v((n >> B) + 1);
	for (int i = 0; i < n; i++) std::cin >> a[i][0], a[i][1] = 1;
	auto pushdown = [&] (int p)
	{
		if (!v[p]) return;
		for (int i = p << B; i < n and (i >> B) == p; i++) a[i][0] += v[p];
		v[p] = 0;
	};
	auto calc = [&] (int p)
	{
		t[p] = Poly(); t[p][0] = 1;
		for (int i = p << B; i < n and (i >> B) == p; i++)
			for (int j = 19; ~j; j--) (t[p][j] *= a[i][0]) += j ? t[p][j - 1] : 0;
	};
	for (int i = 0; i <= (n >> B); i++) calc(i);
	for (int o, l, r; q--; )
		if (std::cin >> o >> l >> r, l--, r--, o == 1)
		{
			unsigned w; std::cin >> w;
			if ((l >> B) == (r >> B))
			{
				pushdown(l >> B);
				for (int i = l; i <= r; i++) a[i][0] += w;
				calc(l >> B);
			}
			else
			{
				pushdown(l >> B); pushdown(r >> B);
				for (int i = l; (i >> B) == (l >> B); i++) a[i][0] += w;
				for (int i = r; (i >> B) == (r >> B); i--) a[i][0] += w;
				calc(l >> B); calc(r >> B);
				for (int i = (l >> B) + 1; i <= (r >> B) - 1; i++) t[i].trans(w), v[i] += w;
			}
		}
		else
		{
			unsigned ans = 1;
			if ((l >> B) == (r >> B))
			{
				pushdown(l >> B);
				for (int i = l; i <= r; i++) ans *= a[i][0];
			}
			else
			{
				pushdown(l >> B); pushdown(r >> B);
				for (int i = l; (i >> B) == (l >> B); i++) ans *= a[i][0];
				for (int i = r; (i >> B) == (r >> B); i--) ans *= a[i][0];
				for (int i = (l >> B) + 1; i <= (r >> B) - 1; i++) ans *= t[i][0];
			}
			std::cout << (ans << 12 >> 12) << '\n';
		}
	double t_end = clock();
	std::cerr << (t_end - t_begin) / CLOCKS_PER_SEC << std::endl;
	return 0;
}