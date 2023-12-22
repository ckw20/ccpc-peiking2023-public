#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

mt19937 rnd(time(0) ^ getpid());
int gen(int L, int R){return L + (int)(rnd() % (R - L + 1));}

int main(){
	for(int i = 1 ; i <= 22 ; ++i){
		freopen((to_string(i) + ".in").c_str() , "w" , stdout);
		int N = gen(99000, 100000);
		int X = i - 1;
		cout << N << endl;
		for(int i = 1 ; i <= N ; ++i)
			cout << (char)(gen(0 , 20) < X ? !!(rnd() % 10) + '0' : '?');
		cout << endl;
		fclose(stdout);
		system(("std.exe < " + to_string(i) + ".in > " + to_string(i) + ".ans").c_str());
	}
	return 0;
}
