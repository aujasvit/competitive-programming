//Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI2002

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int dp[1000006][8];
int n;
int mod = 1000000007;

int ans() {
	for(int i = 1; i <= 7; i++) {
		dp[1][i] = 0;
	}
	dp[1][7] = 1;
	for(int i = 1; i <= 7; i++) {
		dp[2][i] = 0;
	}
	dp[2][7] = 1;

	dp[3][1] = dp[3][4] = 1;
	dp[3][3] = dp[3][6] = dp[3][2] = dp[3][5] = 0;
	dp[3][7] = 2;

	for(int i = 4; i <= n; i++) {
		for(int j = 0; j <= 7; j++) {
			dp[i][j] = 0;
		}

		dp[i][6] += dp[i - 1][1] % mod;
		dp[i][1] += dp[i - 3][1] % mod;

// 		dp[i][2] += dp[i - 3][2] % mod;

		dp[i][7] += dp[i - 2][3] % mod;
		dp[i][3] += dp[i - 3][3] % mod;

		dp[i][3] += dp[i - 1][4] % mod;
		dp[i][4] += dp[i -3][4] % mod;

	//	dp[i][5] += dp[i - 3][5] % mod;

		dp[i][7] += dp[i - 2][6] % mod;
		dp[i][6] += dp[i - 3][6] % mod;

		dp[i][7] += (dp[i - 1][7] + dp[i - 3][7])%mod;
		dp[i][1] += dp[i - 3][7]%mod;
		dp[i][4] += dp[i - 3][7]%mod;
		
		


	}


	return dp[n][7] % mod;
}

int dodo() {
    int dpd[n + 10];
    dpd[0] = 0;
    dpd[1] = 0;
    dpd[2] = 1;
    dpd[3] = 1;
    for(int i = 4; i <= n; i++) dpd[i] = (dpd[i - 3] + dpd[i - 2])%mod;
    
    return dpd[n];
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		int k;
		cin >> k >> n;
		if(k == 1) {
		  if(n % 3 == 0) cout << 1 << endl;
		  else cout << 0 << endl;
		  continue;
		}
		if(k == 2) {
		    cout << dodo() << endl;
		    continue;
		}
		cout << ans() << endl;
	}
	return 0;
}
