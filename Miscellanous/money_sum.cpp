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
	int n, ans = 0; cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		ans += a[i];
	}

	sort(all(a));
	int dp[n + 10][ans + 10];

	for(int row = 0, col = 0; col <= ans; col++) {
		dp[row][col] = 0;
	}

	for(int row = 0, col = 0; row <= n; row++) {
		dp[row][col] = 1;
	}

	for(int row = 1; row <= n; row++) {
		for(int col = 1; col <= ans; col++) {
			if(col - a[row - 1] >= 0)dp[row][col] = (dp[row - 1][col] or dp[row - 1][col - a[row - 1]]);
			else dp[row][col] = dp[row - 1][col];
		}
	}

	vector <int> fu;
	for(int i = 1; i <= ans; i++) {
		if(dp[n][i])fu.pb(i);
	}

	cout << fu.size() << endl;
	for(int i = 0; i < fu.size(); i++)cout << fu[i] << " ";
	return 0;
}

