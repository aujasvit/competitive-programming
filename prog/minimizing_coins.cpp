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
	vector <int> a(n), dp(x + 10);
	for(int i = 0; i < n; i++) cin >> a[i];


	dp[0] = 0;
	
	for(int i = 1; i <= x + 1; i++) {
		dp[i] = INT_MAX;
		for(int j = 0; j < n; j++) {
			int curr = a[j];
			if(i - a[j] >=0 and dp[i - a[j]] != -1) {
				dp[i] = min(dp[i], dp[i - a[j]] + 1);
			}
		}
		if(dp[i] == INT_MAX)dp[i] = -1;
	}

	cout << dp[x] << endl;
	return 0;
}

