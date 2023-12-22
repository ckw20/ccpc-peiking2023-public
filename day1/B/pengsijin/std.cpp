#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int _ = 1e5 + 7 , B = 64;
ull S[_ / B + 3] , Q[_ / B + 3] , T[_ / B + 3];
ull getval(ull* arr , int l , int r){
	if(r < 0) return 0;
	int offset = max(-l , 0); l += offset;
	int pl = l / B , pr = r / B , ll = l % B , lr = r % B; ull ans;
	if(pl == pr) 
		ans = arr[pl] << (B - lr - 1) >> (B - lr - 1 + ll);
	else ans = arr[pl] >> ll | arr[pr] << (B - lr - 1);
	return ans << offset;
}
void setval(ull *arr, int p, bool f){if(f) arr[p / B] |= 1ull << (p % B); else arr[p / B] &= ~(1ull << (p % B));}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; string s; cin >> N >> s;
	for(int i = 0 ; i < N ; ++i) 
		if(s[i] == '1') setval(S , i , 1); 
		else if(s[i] == '?') setval(Q , i , 1); 
	for(int i = 1 ; i <= N ; ++i){
		int ans = 0;
		if(i < B){
			for(int j = 0 ; j < N ; ++j){
				setval(T , j , getval(Q , j , j) ? getval(T , j - i , j - i) : getval(S , j , j));
				ans += getval(T , j , j);
			}
		}else{
			for(int j = 0 ; j <= (N + B - 1) / B ; ++j){
				ull s = S[j] , q = Q[j] , t = getval(T , j * B - i , j * B + B - 1 - i);
				T[j] = s | q & t;
				ans += __builtin_popcountll(T[j]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}