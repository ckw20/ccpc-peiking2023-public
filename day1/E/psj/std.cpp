#include<bits/stdc++.h>
using namespace std;

const int _ = 2003; int dp[_][_] , A[_] , B[_] , N , M;
void chkmin(int &a , int b){a = min(a , b);}

int main(){
	cin >> M >> N; memset(dp , 0x3f , sizeof(dp)); dp[M][N] = 0;
	for(int i = 1 ; i <= M ; ++i) cin >> A[i];
	for(int i = 1 ; i <= N ; ++i) cin >> B[i];
	int ans = 1e9;
	for(int i = M ; ~i ; --i)
		for(int j = N ; ~j ; --j){
			if(!i || !j){chkmin(ans , dp[i][j]); continue;}
			if(A[i] == B[j] || A[i] == 1 || B[j] == 1) chkmin(dp[i - 1][j - 1] , dp[i][j]);
			chkmin(dp[i - 1][j], dp[i][j] + 1); chkmin(dp[i][j - 1], dp[i][j] + 1);
		}
	cout << ans;
	return 0;
}