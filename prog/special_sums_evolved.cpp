#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int a[1000009], b[1000009], n;

int back_stuff() {

	int sb[n + 10];
	b[0] = a[0] = 0;
	int dp[n + 10];
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		sb[i] = sb[i - 1] - a[i - 1] + b[i - 1] + a[i];
		dp[i] = max(dp[i - 1], sb[i]);
	}
	int ans = 0;

	int back[n + 10];
	back[0] = back[n + 1] = 0;
	for(int i = n; i >= 1; i--) {
		back[i] = back[i + 1] + b[i];
	}

	for(int i = 2; i <= n; i++) {
		ans = max(ans, back[i + 1] + a[i] + dp[i]);
	}



	return ans;
}

int front_stuff() {
	int dp[n + 10];
	int sb[n + 10];
	sb[0] = 0;
	for(int i = 1; i <= n; i++) {
		sb[i] =  b[i] + sb[i - 1];
		dp[i] = max(dp[i - 1], a[i] - sb[i]);
	}

	int ans = 0;

	for(int i = 1; i <= n; i++) {
		ans = max(ans, dp[i - 1] + a[i] + sb[i - 1]);
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];

	cout << front_stuff() << endl;
	return 0;
}

