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
	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;
		vector <int> a(n);

		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}

		vector <int> dp(n + 10, 0);
		dp[n - 1] = 1;
		for(int i = n-2; i >= 0; i--) {
			dp[i] = 1;
			if(a[i] * a[i + 1] < 0) {
				dp[i] += dp[i + 1];	
			}
		}

		for(int i = 0; i < n; i++) {
			cout << dp[i] << " ";
		}
		cout << endl;
	}		
	return 0;
}

