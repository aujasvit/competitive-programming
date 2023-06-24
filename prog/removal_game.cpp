#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int dp[5020][5010][2];
int n;
vector <int> a;
int ans(int l, int r, int curr) {
	if(l < 0) return INT_MIN;
	if(r >= n) return INT_MIN;
	if(l > r) return INT_MIN;
	if(dp[l][r][curr] != -1) return dp[l][r][curr];
	if(l == r) {
		if(curr == 1)dp[l][r][curr] = a[l];
		else dp[l][r][curr] = 0;
		return dp[l][r][curr];
	}



	int dodo = (curr + 1)%2;
	
	if(curr == 0) {
		dp[l][r][curr] = min(ans(l, r - 1, dodo), ans(l + 1, r, dodo));
		return dp[l][r][curr];
	} else {
	dp[l][r][curr] = max(ans(l, r - 1, dodo) + a[r], ans(l + 1, r, dodo) + a[l]);
	return dp[l][r][curr];	
	}
	

}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >>n;
	a.resize(n);
	for(int i = 0;i < n; i++) cin >> a[i];
	//dp[l][r] = max(dp[l - 1][r] + a[l], dp[l][r - 1] + a[r]);
	//int dp[l + 10][r + 10][2];

	for(int i = 0; i < 5010; i++) {
		for(int j = 0; j < 5010; j++) {
			dp[i][j][0] = dp[i][j][1] = -1;
		}
	}

	cout << ans(0, n - 1, 1);
	
	return 0;
}

