#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int n, k;

void ans() {
	cin >> n >> k;
	int dp[n + 2][2];
	dp[0][0] = dp[0][1] = 0;
	dp[1][0] = 0; dp[1][1] = 1;
	dp[2][0] = 0; dp[2][1] = 1;
	dp[3][0] = 0; dp[3][1] = 2;
	dp[4][0] = 1; dp[4][1] = 3;
	for(int i = 5; i <= n; i++) {
		dp[i][0] = dp[i - 3][0] + dp[i - 4][1];
		dp[i][1] = dp[i - 3][1] + dp[i - 1][1] + dp[i - 2][0];
	}

	cout << dp[n][1] << endl;
}


signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t; cin >> t;
	while(t--) {
		ans();
	}

	return 0;
}

