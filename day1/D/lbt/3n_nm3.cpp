#include <cmath>
#include <cstring>

#include <algorithm>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

typedef unsigned long long ull;

const int Mod = 998244353;

void add(int& x, int y) { if ((x += y) >= Mod) x -= Mod; }
void sub(int& x, int y) { if ((x -= y) < 0) x += Mod; }
void fam(int& x, int y, int z) { x = (x + y * (ull)z) % Mod; }

const int STATES = 729;

int N, M;
int a[5][50];
int pw3[6];

int states1, states2;
int digits1[STATES][6], lift1[STATES][6];
int digits2[STATES][6], lift2[STATES][6];

// state, dist, delta
int dp1[STATES][60][60], dp2[STATES][60][60], tmp[STATES][60][60];

int reduce3(int x) { if (x == 2) x = -1; return x; }

void prepare(int n, int& states, int digits[][6], int lift[][6]) {
	states = pow(3, n);
	for (int i = 0; i != states; ++i) {
		int tmp = i;
		for (int j = 0; j != n; ++j) {
			digits[i][j] = tmp % 3;
			tmp /= 3;
		}
		for (int j = 1; j != n; ++j)
			lift[i][j] = lift[i][j - 1] + reduce3((digits[i][j] - digits[i][j - 1] + 3) % 3);
	}
}

int main() {

	std::cin >> N >> M;
	for (int i = 0; i != N; ++i)
		for (int j = 0; j != M; ++j)
			std::cin >> a[i][j];

	pw3[0] = 1;
	for (int i = 1; i <= N; ++i) pw3[i] = pw3[i - 1] * 3;

	prepare(N, states1, digits1, lift1);
	prepare(N + 1, states2, digits2, lift2);

	for (int i = 0; i != states1; ++i) {
		bool flag = true;
		for (int j = 0; j != N; ++j) {
			if (a[j][0] != 3 && a[j][0] != digits1[i][j]) {
				flag = false;
				break;
			}
		}

		if (!flag) continue;

		int min = 1e9, pos = 0;
		for (int j = 0; j != N; ++j) {
			if (lift1[i][j] < min) {
				min = lift1[i][j];
				pos = j;
			}
		}
		dp1[i][pos][0] = 1;
	}

	for (int i = 1; i != M; ++i) {
		memset(dp2, 0, sizeof(dp2));
		for (int j = 0; j != states1; ++j) {
			int min = *std::min_element(lift1[j], lift1[j] + N);
			for (int c = 0; c != 3; ++c) {
				if (a[0][i] != 3 && a[0][i] != c) continue;
				int val = lift1[j][0] + reduce3((c - digits1[j][0] + 3) % 3);
				
				int nxs = j * 3 + c;

				int newmin = std::min(min, val);

				for (int dist = 0; dist != 60; ++dist)
					for (int delta = 0; delta != 60; ++delta) {
						if (!dp1[j][dist][delta]) continue;
						int oldmin = min - delta;
						if (oldmin < val)
							add(dp2[nxs][dist][newmin - oldmin], dp1[j][dist][delta]);
						else if (oldmin == val)
							add(dp2[nxs][std::min(dist, i)][0], dp1[j][dist][delta]);
						else
							add(dp2[nxs][i][0], dp1[j][dist][delta]);
					}
			}
		}

		for (int j = 1; j != N; ++j) {
			memset(tmp, 0, sizeof(tmp));

			for (int k = 0; k != states2; ++k) {
				int min = *std::min_element(lift2[k], lift2[k] + N + 1);
				for (int c = 0; c != 3; ++c) {
					if (a[j][i] != 3 && a[j][i] != c) continue;
					int val = lift2[k][j - 1] + reduce3((c - digits2[k][j - 1] + 3) % 3);
					if (abs(val - lift2[k][j + 1]) > 1) continue;

					int nxs = k + (c - digits2[k][j]) * pw3[j];
					int newmin = *std::min_element(lift2[nxs], lift2[nxs] + N + 1);

					for (int dist = 0; dist != 60; ++dist)
					for (int delta = 0; delta != 60; ++delta) {
						if (!dp2[k][dist][delta]) continue;
						int oldmin = min - delta;
						if (oldmin < val)
							add(tmp[nxs][dist][newmin - oldmin], dp2[k][dist][delta]);
						else if (oldmin == val)
							add(tmp[nxs][std::min(dist, i + j)][0], dp2[k][dist][delta]);
						else
							add(tmp[nxs][i + j][0], dp2[k][dist][delta]);
					}
				}
			}

			memcpy(dp2, tmp, sizeof(tmp));
		}

		memset(dp1, 0, sizeof(dp1));
		for (int j = 0; j != states2; ++j) {
			int min = *std::min_element(lift2[j], lift2[j] + N + 1);
			int nxs = j % pw3[N];
			int newmin = *std::min_element(lift2[j], lift2[j] + N);
			for (int dist = 0; dist != 60; ++dist)
				for (int delta = 0; delta != 60; ++delta) {
					if (!dp2[j][dist][delta]) continue;
					int oldmin = min - delta;
					add(dp1[nxs][dist][newmin - oldmin], dp2[j][dist][delta]);
				}
		}
	}

	int count = 0, sum = 0;
	for (int i = 0; i != states1; ++i) {
		for (int j = 0; j != 60; ++j) {
			for (int k = 0; k != 60; ++k) {
				add(count, dp1[i][j][k]);
				fam(sum, dp1[i][j][k], j);
			}
		}
	}
	std::cout << count << ' ' << sum << '\n';

	return 0;
}
