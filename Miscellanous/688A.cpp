#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int n, q, k;

int a[100007];
int dp[100007], dp2[100007];

void ans() {
	int l, r;
	while(q--) {
		//if(dp[r] - dp[l - 1]) {
		cin >> l >> r;
	
		//int l1 = dp2[r - 1]-dp2[l + 1];
		int aa;
		aa = dp[r] - dp[l - 1];
		aa -= dp[l] - dp[l - 1] + dp[r] - dp[r - 1];
		aa -= 2;
		aa += a[l + 1] - 1;
		aa += k - a[r - 1];
		cout << aa << endl;
	}
}

void fill() {
	dp[0] = 0;
	dp2[0] = 0;
	

	for(int i = 1; i <= n; i++) {
		int l1 = a[i - 1] + 1;
		int l2 = (a[i + 1]  - 1);
		if(i == 1) l1 = 1;
		if(i == n) l2 = k;
		dp2[i] = l2 - l1;
 		dp2[i] += dp2[i - 1];
		cout << dp2[i] << " ";
	}
	cout << endl;

}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> q >> k;
	fill();
	ans();
	return 0;
}

