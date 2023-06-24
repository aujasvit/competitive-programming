#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define all(a) a.begin(), a.end()
 
int w[maxn], v[maxn];
int dp[105][1008];
int n, W;

int ans(int i, int val) {
	if(i > n or i < 1) {
		return -1;
	}

	dp[i][val] = INT_MIN;

	int k = dp[i - 1][val];
	int l = dp[i - 1][val - 1] - w[i];
	
	if(k >= 0 and l >= 0) dp[i][val] = max(k, l);
	else if(k >= 0) dp[i][val] = k;
	else if(l >= 0) dp[i][val] = l;
	else dp[i][val] = -1;

	return dp[i][val];
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> W;
 
	for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
		int ans = INT_MIN;
	for(int i = 0; i <= 1000; i++) {
		if(dp[n][i] >= 0) ans = max(ans, dp[n][i]);
	}

	cout << ans << endl;
 
 
	return 0;
}