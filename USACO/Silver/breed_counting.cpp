//Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=572

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
	freopen("bcount.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("bcount.out", "w", stdout);

	//os_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	int a[n + 5];
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int dp[n + 2][4];
		for(int j = 1; j <= 3; j++) dp[0][j] = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= 3; j++) dp[i][j] = dp[i - 1][j];

		dp[i][a[i]]++;
	}


	for(int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;

		for(int j = 1; j <= 3; j++) {
			cout << dp[r][j] - dp[l - 1][j];
			if(j != 3)cout << " ";
		}
		cout << endl;
	}
	return 0;
}

