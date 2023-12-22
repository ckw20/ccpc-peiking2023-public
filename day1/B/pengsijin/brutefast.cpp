#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 7; bool flg[_] , ans[5][_]; int sum[5];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; string s; cin >> N >> s;
	for(int i = 0 ; i < N ; ++i) if(s[i] != '?') ans[0][i] = s[i] - '0'; else flg[i] = 1;
	for(int i = 1 ; i <= N ; i += 4){
		memset(sum , 0 ,sizeof(sum));
		for(int j = 0 ; j < N ; ++j){
			bool f = flg[j] , pa = ::ans[0][j];
			sum[1] += (::ans[1][j] = f ? (j < i ? 0 : ::ans[1][j - i]) : pa);
			sum[2] += (::ans[2][j] = f ? (j < i + 1 ? 0 : ::ans[2][j - i - 1]) : pa);
			sum[3] += (::ans[3][j] = f ? (j < i + 2 ? 0 : ::ans[3][j - i - 2]) : pa);
			sum[4] += (::ans[4][j] = f ? (j < i + 3 ? 0 : ::ans[4][j - i - 3]) : pa);
		}
		cout << sum[1] << '\n';
		if(i + 1 <= N) cout << sum[2] << '\n';
		if(i + 2 <= N) cout << sum[3] << '\n';
		if(i + 3 <= N) cout << sum[4] << '\n';
	}
	return 0;
}