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
		int kill, make;
		cin >> kill >> make;
		string s;cin >> s;

		int dp[2][s.size() + 10];
		vector <int> fu;

		string d = "";

		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '1') {
				d += "1";
				while(s[i] == '1' and i < s.size()) {
					i++;
				}
				if(i  < s.size() and s[i] == '0')i--;
			} else {
				d += "0";
			}
		}

		for(int i = 0; i < d.size(); i++) {
			if(d[i] == '1') {
				fu.pb(i);
			}
		}
		int ans = fu.size() * kill;
		for(int i = 1; i < fu.size(); i++) {
			int dis = fu[i] - fu[i - 1] - 1;
			if(dis *make < kill) {
				ans -= kill;
				ans += dis*make;
			}
		}

		cout << ans << endl;

	}		
	return 0;
}

