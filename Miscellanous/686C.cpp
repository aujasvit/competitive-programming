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
		bool d = true;
		set <int> fofo;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			fofo.insert(a[i]);
		}
		if(n == 1 or fofo.size() == 1) {
			cout << 0 << endl;
			continue;
		}
		map <int, vector <int> > freq;
		for(int i = 0; i < n; i++) {
			freq[a[i]].pb(i);
		}
	
	int ans = INT_MAX;
	for(int i = 0; i < n; i++) {
		int d = freq[a[i]].size() + 1;
		for(int j = 0; j < freq[a[i]].size(); j++) {
			if(freq[a[i]][j] == 0) {
				d--;

			}
			if(freq[a[i]][j] == n-1) {
				d--;
			}
			if(j > 0 and freq[a[i]][j] == freq[a[i]][j - 1]) d--;
		}
		ans = min(ans, d);
	}
	cout << ans << endl;
}
	return 0;
}

