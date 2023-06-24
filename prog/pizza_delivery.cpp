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
	int t;cin >> t;
	while(t--) {
		int n;cin >> n;
		vector <int> a(n), fuel(n);
		int d = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			a[i]*=2;
			d = max(d, a[i]);
		}
		for(int j = 0; j < n; j++)cin >> fuel[j];

		sort(all(fuel));

		

		vector <int> dp(d + 10,0);
		dp[0] = 0;
		for(int i = 1; i <= d + 2; i++) {
			if(i < fuel[0]) {
				dp[i] = 1000000;
			}
			for(int j = 0; j < fuel.size(); j++) {
				if(fuel[i] <= i) {
					dp[i] = min(dp[i], dp[i - fuel[i]] + 1);
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			ans += dp[a[i]];
		}

		cout << ans << endl;

	}

	return 0;
}

