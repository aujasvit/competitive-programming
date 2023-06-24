#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int n,m, k;
int dp[30][30];
int str[410];
string s;
int dodo;


int ans(int curr, int len) {
	if(curr > n) {
		if(len < k) return INT_MAX;
		return 0;
	}

	if(len == 0) {
		int a1 = INT_MAX;
		for(int i = 1; i <= m; i++) {
			dodo = i;
			int p = dp[str[curr]][i];
			a1 = min(a1, ans(curr + 1, 1) + p);
		}
	} else {
		int a1 = INT_MAX;
		int p = dp[str[curr]][dodo];
		a1 = ans(curr + 1, len + 1) + p;
		int a2 = INT_MAX;
		if(len >= k) {
			for(int i = 1; i <= m; i++) {
				dodo = i;
				a2 = min(a2, ans(curr + 1, 1) + dp[str[curr]][i]);
			}
		}
		return min(a1, a2);
	}
}

// int ans(int curr, int len) {
// 	if(curr > n) {
// 		if(len < k) return INT_MAX;
// 		return 0;
// 	}

// 	if(len == 0) {
// 		int a1 = INT_MAX;
// 		for(int i = 1; i <= m; i++) {
// 			dodo = i;
// 			int p = dp[str[curr]][i];
// 			a1 = min(a1, ans(curr + 1,1) + p);
// 		}
// 		return a1;
// 	} else {
// 		int a1 = ans(curr + 1, len + 1) + dp[str[curr]][dodo];
// 		int a2 = INT_MAX;
// 		if(len >= k) {
// 			for(int i = 1; i <= m; i++) {
// 				dodo = i;
// 				int p = dp[str[curr]][dodo];
// 				a2 = min(a2, ans(curr + 1, 1) + p);
// 			}

// 		}
// 		return min(a1, a2);
// 	}

// }



void sp() {
	//;int a[30][30]
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> dp[i][j];
		}
	}

	for(int alpha = 1; alpha <= m; alpha++) {
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= m; j++) {
				dp[i][j] = min(dp[i][j], dp[i][alpha] + dp[alpha][j]);
			}
		}
	}
	
// 	for(int i = 1; i <= m; i++) {
// 		for(int j = 1; j <= m; j++) {
// 			cout << dp[i][j] << " ";
// 		}
// 		cout << endl;
// 	}

}

signed main() {
	freopen("cowmbat.in", "r", stdin);
     freopen("cowmbat.out", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m >> k;
	cin >> s;
    
	sp();
	for(int i = 0; i < s.size(); i++) {
		int curr = (int)(s[i]) - (int)('a') + 1;
		str[i + 1] = curr;
	}
	//sp();cout << str[1] << str[2] << endl;
	cout << ans(1, 0) << endl;
	return 0;
}
