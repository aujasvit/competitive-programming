//Problem Link: https://cses.fi/problemset/task/1638

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()
int dodo = 1000000007;
signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin >> n;
	vector <string> a(n);
	for(int i = 0; i < n;i++) cin >> a[i];

	int dp[n + 10][n + 10];
	bool d = true;
	for(int row = 0, col = 0; col < n; col++) {
		if(a[row][col] == '*') {
			d = false;
			dp[row][col] = 0;
		}
		if(d) {
			dp[row][col] = 1;
		} else {
			dp[row][col] = 0;
		}
	}
	d = true;
	for(int row = 0, col = 0; row < n; row++) {
		if(a[row][col] == '*') {
			d = false;
			dp[row][col] = 0;
		}
		if(d) {
			dp[row][col] = 1;
		} else {
			dp[row][col] = 0;
		}
	}

	for(int row = 1; row < n; row++) {
		for(int col = 1; col < n; col++) {
			dp[row][col] = 0;
			if(a[row][col] == '*') {
				dp[row][col] = 0;
			} else {
				if(a[row][col - 1] != '*') {
					dp[row][col] += dp[row][col - 1]%dodo;
					dp[row][col] %= dodo;
				}
				if(a[row - 1][col] != '*') {
					dp[row][col] += dp[row - 1][col] % dodo;
					dp[row][col] %= dodo;
				}
			}
		}
	}

	cout << dp[n - 1][n - 1] << endl;	
	return 0;
}

