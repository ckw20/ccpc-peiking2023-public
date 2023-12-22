#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int _ = 5e4 + 7 , B = 64;
struct Bitset{
	vector < ull > bit; int sz; Bitset(int _sz = 0){bit.resize(_sz / B + 1); sz = _sz;}
	void expand(int _sz){if(sz != _sz){bit.resize(_sz / B + 1); sz = _sz;}}
	ull& operator [](int x){assert(x <= sz / B); return bit[x];}
	void set(int x){assert(x < sz); bit[x / B] |= 1ull << (x % B);}
	Bitset pick(int l , int r){
		Bitset ans(r - l + 1); int lp = l / B , rp = r / B , t = l % B;
		if(lp == rp) ans[0] = bit[lp] << (B - 1 - r % B) >> (B - 1 - r % B) >> t;
		else
			if(!t){
				for(int i = lp ; i < rp ; ++i) ans[i - lp] = bit[i];
				ans[rp - lp] = bit[rp] << (B - 1 - r % B) >> (B - 1 - r % B);
			}else{
				ull val = bit[lp] >> t;
				for(int i = lp + 1 ; i < rp ; ++i){
					ans[i - lp - 1] = val | (bit[i] << (B - t));
					val = bit[i] >> t;
				}
				ans[rp - lp - 1] = val | (bit[rp] << (B - 1 - r % B) >> (B - 1 - r % B) << (B - t));
				if(B - t + r % B + 1 > B) ans[rp - lp] = bit[rp] << (B - 1 - r % B) >> (B - 1 - r % B) >> t;
			}
		return ans;
	}
	int popcount(){int sum = 0; for(auto t : bit){sum += __builtin_popcountll(t);} return sum;}
}X , Y;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; string s; cin >> N >> s; X = Y = Bitset(N);
	for(int i = 0 ; i < N ; ++i) if(s[i] == '1') X.set(i); else if(s[i] == '?') Y.set(i);
	Bitset val , p , q; 
	for(int i = 1 ; i <= N ; ++i){
		int ans = 0; val = Bitset(i);
		for(int j = 0 ; j < N ; j += i){
			p = X.pick(j , min(j + i - 1 , N - 1)); q = Y.pick(j , min(j + i - 1 , N - 1));
			q.expand(i); p.expand(i);
			for(int i = 0 ; i < val.bit.size() ; ++i) val[i] = val[i] & q[i] | p[i];
			ans += val.popcount();
		}
		cout << ans << '\n';
	}
	return 0;
}