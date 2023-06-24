#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, x;
	cin >> n >> x;
	int a[n];
	int dodo = 1000000007;
	for(int i = 0; i < n; i++) cin >> a[i];
	//int dp[n + 1][x];
	//dp[i][x] = sum(dp[i - 1][x - j*x])
	//		

	int dpold[x + 1], dpnew[x + 1];
	dpold[0] = dpnew[0] = 1;

	for(int i = 1; i <= x; i++) {
		if(i % a[0] == 0) dpold[i] = 1;
		else dpold[i] = 0;

		dpnew[i] = dpold[i]% dodo;
	}

	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= x; j++) {
			dpnew[j] = 0;
			if(j >= a[i]) {
				dpnew[j] += dpnew[j - a[i]] % dodo;
			}
			dpnew[j] += dpold[j] % dodo;
			dpnew[j] %= dodo;
		}
		for(int j = 0; j <= x; j++) {
			dpold[j] = dpnew[j];
		}
	}

	cout << dpold[x] << endl;
	return 0;
}

