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
		int n, q;
		cin >> n  >> q;
		string s;
		cin >> s;
		vector <vector <int> > dp(2);
		dp[0].resize(n);dp[1].resize(n);
		for(int i = 0; i < n; i++) {
			if(s[i] == '0') {
				dp[0][i] = 1;
				dp[1][i] = 0;
			} else {
				dp[0][i] = 0;
				dp[1][i] = 1;
			}
			if(i > 0) {
				dp[0][i] += dp[0][i - 1];
				dp[1][i] += dp[1][i - 1];
			}



		}
		map <char, int> d;
		d['0'] = 0;d['1'] = 1;
		for(int i = 0; i < n; i++) {
			int l, r;
			cin >> l >> r;
			if(r - l == 1) {
				cout << "NO" << endl;
				continue;
			}
			int c1, c2;
			c1 = d[s[l - 1]], c2 = d[s[r - 1]];
			if(dp[l - 1][c1] > 1 or (dp[n - 1][c2] > 1 and r < n)) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
		
	}		
	return 0;
}

