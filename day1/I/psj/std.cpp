#include<bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7; string s;
int f[1003] , g[1003][603][2] , N , L , endp[353] , bel[603];
void inc(int &a , int b){a = (a + b >= P ? a + b - P : a + b);}

string subs(int from, int to){return string(s.begin() + from, s.begin() + to);}
string getpresuf(int pos , bool f){return f ? subs(endp[bel[pos] - 1] , pos + 1) : subs(pos , endp[bel[pos]]);}
int len(int pos){return endp[pos] - endp[pos - 1];}

int maxpal[603][603];
int getmaxpal(int l , int r){
	if(l < 0 || r < 0 || l >= s.size() || r >= s.size()) return 0;
	if(~maxpal[l][r]) return maxpal[l][r];
	return maxpal[l][r] = (s[l] != s[r] ? 0 : getmaxpal(l + 1 , r - 1) + 1);
}

void trans(int len , int val , int ll , int lr , int rl , int rr){
	if(len < 0) return;
	int llen = lr - ll , rlen = rr - rl;
	if(getmaxpal(ll , rr - 1) < min(llen , rlen)) return;
	if(llen == rlen) inc(f[len] , val);
	else if(llen > rlen) inc(g[len][ll + rlen][0] , val);
	else inc(g[len][rr - 1 - llen][1] , val);
}
bool ispal(string s){string t = s; reverse(s.begin() , s.end()); return t == s;}

int main(){
	cin >> N >> L; memset(maxpal , -1 , sizeof(maxpal));
	for(int i = 1 ; i <= N ; ++i){
		string t; cin >> t; s += t; endp[i] = s.size();
		for(int j = endp[i - 1] ; j < endp[i] ; ++j) bel[j] = i;
	}
	f[L] = 1;
	for(int i = L ; i ; --i){
		for(int j = 1 ; j <= N ; ++j)
			for(int k = 1 ; k <= N ; ++k)
				trans(i - len(j) - len(k) , f[i] , endp[j - 1] , endp[j] , endp[k - 1] , endp[k]);
		for(int j = 0 ; j < s.size() ; ++j)
			for(int k = 1 ; k <= N ; ++k){
					trans(i - len(k) , g[i][j][0] , j , endp[bel[j]] , endp[k - 1] , endp[k]);
					trans(i - len(k) , g[i][j][1] , endp[k - 1] , endp[k] , endp[bel[j] - 1] , j + 1);
				}
	}
	int ans = f[0];
	for(int i = 0 ; i < s.size() ; ++i)
		for(int j = 0 ; j < 2 ; ++j) if(ispal(getpresuf(i , j))) inc(ans , g[0][i][j]);
	for(int i = 1 ; i <= N ; ++i) if(ispal(subs(endp[i - 1] , endp[i]))) inc(ans , f[len(i)]);
	cout << ans;
	return 0;
}