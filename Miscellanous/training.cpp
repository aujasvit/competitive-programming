#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int n, ev = 0;
int a[6000];
int dodo[6000];

void fill(int s) {
	dodo[0] = s;
	for(int i = 1; i <= n; i++) {
		int k = dodo[i - 1];
		int fu = 0;
		while(k > 0) {
			fu += k % 10;
			k /= 10;
		}
		fu = fu*fu*fu;
		dodo[i] = dodo[i - 1] + fu;
	}
}


int fin_ans(int s) {
	fill(s);
	int dp[n + 2][n + 2];

	//current, number of times i have added;

	dp[0][0] = 0;

	for(int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + (dodo[0] * a[i]);
	}

	for(int i = 1; i <= n; i++) {
		dp[0][i] = 0;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(j > i) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = max(dp[i - 1][j] + dodo[j]*a[i], dp[i][j - 1]);
		}
	}

	int fu = 0;
	for(int i = 0; i <= n; i++) fu = max(fu, dp[n][i]);

	return fu;
}


signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int s;
	cin >> n >> s;
	for(int i = 1; i <= n; i++) cin >> a[i];

	cout << fin_ans(s) << endl;
	return 0;
}

