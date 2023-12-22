#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 7; bool flg[_] , ans[_];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; string s; cin >> N >> s;
	for(int i = 0 ; i < N ; ++i) if(s[i] != '?') ans[i] = s[i] - '0'; else flg[i] = 1;
	for(int i = 1 ; i <= N ; ++i){
		int ans = 0;
		for(int j = 0 ; j < N ; ++j){
			::ans[j] = flg[j] ? (j < i ? 0 : ::ans[j - i]) : ::ans[j];
			ans += ::ans[j];
		}
		cout << ans << '\n';
	}
	return 0;
}