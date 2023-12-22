#include <bits/stdc++.h>
constexpr long long inf = 1LL << 60;
signed main ()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int n, m; std::cin >> n >> m;
	int dfs_times = 0, cnt = 0; std::vector<int> dfn(n + 1), low(n + 1), vis(n + 1), col(n + 1), sol(n + 1), scc;
	std::stack<int, std::vector<int>> st; std::vector<std::vector<std::pair<int, int>>> e(n + 1), g(n + 1);
	for (int i = 1, u, v, w; i <= m; i++) std::cin >> u >> v >> w, e[u].emplace_back(v, w);
	std::function<void (int)> tarjan = [&] (int u)
	{
		dfn[u] = low[u] = ++dfs_times; st.push(u); vis[u] = 1;
		for (auto [v, w]: e[u])
			if (!dfn[v]) tarjan(v), low[u] = std::min(low[u], low[v]);
			else if (vis[v]) low[u] = std::min(low[u], dfn[v]);
		if (low[u] == dfn[u])
		{
			col[u] = ++cnt;
			while (st.top() != u) col[st.top()] = cnt, vis[st.top()] = 0, st.pop();
			vis[u] = 0; st.pop();
		}
	};
	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	for (int u = 1; u <= n; u++) for (auto [v, w]: e[u]) if (col[u] == col[v]) g[u].emplace_back(v, w);
	long long ans = inf; std::vector<long long> dis(n + 1); std::vector<std::vector<std::pair<int, long long>>> E(n + 1);
	std::function<void (int)> dfs = [&] (int u)
	{
		vis[u] = true; scc.emplace_back(u);
		for (auto [v, w]: g[u])
			if (!vis[v])
			{
				long long sw = w;
				while (g[v].size() == 1 and !vis[g[v][0].first]) sw += g[v][0].second, v = g[v][0].first;
				E[u].emplace_back(v, sw); dfs(v);
			}
			else E[u].emplace_back(v, w);
	};
	auto solve = [&] (void)
	{
		for (int s: scc)
		{
			for (int t: scc) dis[t] = inf;
			std::priority_queue<std::pair<long long, int>> q; q.emplace(dis[s] = 0, s);
			while (!q.empty())
			{
				auto [d, u] = q.top(); q.pop(); if (d + dis[u] != 0) continue;
				for (auto [v, w]: E[u]) if (dis[v] > dis[u] + w) q.emplace(-(dis[v] = dis[u] + w), v);
			}
			for (int t: scc) for (auto [x, w]: E[t]) if (x == s) ans = std::min(ans, dis[t] + w);
		}
	};
	for (int i = 1; i <= n; i++) if (!sol[col[i]]) sol[col[i]] = true, dfs(i), solve(), std::vector<int>().swap(scc);
	std::cout << (ans == inf ? -1 : ans) << std::endl;
	return 0;
}