//Problem Link:  https://cses.fi/problemset/task/1746

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int n, m;
int a[100009];
int mod = 1000000007;

int dodo() {
	
	int dp[n + 100][m + 100];

	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m + 5; j++) {
			dp[i][j] = 0;
		}
	}

	if(a[1] != 0) {
		dp[1][a[1]] = 1;
	} else {
		for(int i = 1; i <= m; i++) {
			dp[1][i] = 1;
		}
	}

	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
            
            if(a[i] != 0) {
                 if(j != a[i]) continue;
            }
        
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
				dp[i][j] %= mod;
		}
	}
	
// 	for(int i = 1; i <= n; i++) {
// 	    for(int j = 1; j <= m; j++) {
	    
// 	        cout << dp[i][j] << " ";
// 	    }
// 	    cout << endl;
	    
// 	}

	int ans = 0;

	for(int i = 1; i <= m; i++) {ans += dp[n][i]; ans %= mod;}


	return ans;

}

void inp() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	inp();

	cout << dodo() << endl;
	return 0;
}

