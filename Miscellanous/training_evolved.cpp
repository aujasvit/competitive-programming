#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int a[5010], s;
int n;
int change[5010];



void fill() {
	change[0] = s;
	for(int i = 1; i <= n; i++) {
		int k = change[i - 1];
		int fu = 0;
		while(k > 0) {
			fu += k%10;
			k /= 10;
		}
		change[i] = change[i - 1] + fu*fu*fu;
	}

}

int lmao() {
	int dp[n][m];
	for(int i = 0; i <=n; i++) {
		dp[i][0] = dp[i - 1][0] + a[i]*change[0];
		dp[0][i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i > j) {
				dp[i][j] = INT_MIN;
			} else if(i == j) {
				dp[i][j]=0;
			} else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j] + a[i]*change[j]);
			}
		}
	}

	int fu = 0;
	for(int i = 0; i <= n; i+) fu = max(fu, dp[n][i]);

	return fu;
}

int ans(int curr, int have) {
	if(have < 0) return 0;
	if(curr < 0) return 0;
	if(have > curr) return INT_MIN;
	if(have == curr) return 0;

	int k1 = ans(curr - 1, have - 1);
	int k2 = ans(curr - 1, have) + a[curr]*change[have];

	return max(k1,k2);
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	/*
	input
	*/

	cin >> n >> s;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	fill();


	cout << lmao() << endl;


	return 0;
}

