#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

vector <int> classified;
vector <int> pub;
vector <int> times;

int n, m;

int ans() {
	int dp[n + 2][m + 2];

	dp[0][0] = 0;
	for(int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + classified[i];
	}

	for(int j = 1; j <= m; j++) {
		int k1 = dp[0][j - 1];
		if(k1 > times[j]) dp[0][j] = INT_MAX;
		else dp[0][j] = max(dp[0][j - 1] + pub[j], times[j]);
	}

	for(int i = 2; i <= n; i++) {
		for(int j = 2; j <= m; j++) {
			int t1 = dp[i - 1][j], t2 = dp[i][j - 1];
			int k1, k2;
			k1 = t1 + classified[i];
			if(t2 >= times[j]) k2 = INT_MAX;
			else k2 = max(t2 + pub[j], times[j]);
			dp[i][j] = min(k1,k2);
		}
	}

	return dp[n][m];


}


signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		classified.clear();
		pub.clear();times.clear();
		classified.resize(n + 2);pub.resize(m + 2);times.resize(m + 2);
		for(int i = 1; i <= n; i++) {
			cin >> classified[i];
		}
		for(int i = 1; i <= m; i++) cin >>pub[i];

		for(int i = 1; i <= m; i++) cin >> times[i];

		vector <pii> fu;
		for (int i = 1; i <= m; ++i)
		{
			fu.pb(mp(times[i], pub[i]));
		}
		sort(all(fu));

		for (int i = 1; i <= m; ++i)
		{   cout << fu[i].fr << " " << fu[i].sc << endl;
			pub[i] = fu[i].sc;
			times[i] = fu[i].fr;
			/* code */
		}

		cout << ans() << endl;

	}		
	return 0;
}





