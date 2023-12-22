#include<bits/stdc++.h>
using namespace std;

const int _ = 1e6 + 7; struct dat{int v , bel;}arr[_ << 1]; int N;
bool operator <(dat p , dat q){return p.v < q.v;}

bool check(){
	static bool flg[_]; memset(flg , 0 , sizeof(bool) * (N + 1)); long long sum = 0;
	for(int i = 1 ; i <= N ; ++i){
		sum += arr[i].bel; if(flg[abs(arr[i].bel)]) return 1;
		flg[abs(arr[i].bel)] = 1;
	}
	return abs(sum) == 1ll * N * (N + 1) / 2;
}
bool checkswap(int p , int q){
	swap(arr[p], arr[q]); bool f = check();
	swap(arr[p], arr[q]); 
	//cerr << f << endl;
	return f;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N; long long sum = 0 , ans = 0;
	for(int i = 1 ; i <= 2 * N ; i += 2){
		cin >> arr[i].v; arr[i].bel = -i / 2 - 1; 
		cin >> arr[i + 1].v; arr[i + 1].bel = i / 2 + 1;
	}
	sort(arr + 1 , arr + 2 * N + 1); for(int i = 1 ; i <= 2 * N ; ++i) sum += (i <= N ? -1 : 1) * arr[i].v;
	if(checkswap(1, 1)) ans = sum;
	else if(checkswap(N, N + 1)) ans = sum - 2 * (arr[N + 1].v - arr[N].v);
	else{
		if(checkswap(N - 1 , N + 1)) ans = max(ans, sum - 2 * (arr[N + 1].v - arr[N - 1].v));
		if(checkswap(N , N + 2)) ans = max(ans, sum - 2 * (arr[N + 2].v - arr[N].v));
	}
	cout << ans;
	return 0;
}