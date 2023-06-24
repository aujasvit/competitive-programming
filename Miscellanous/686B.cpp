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
	cin >>t;
	while(t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		int mi = INT_MAX;
		map <int, int> freq;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			freq[a[i]]++;
			mi = min(freq[a[i]], mi);
		}
		int ans = INT_MAX, d;
		for(int i = 0; i < n; i++) {
			if(freq[a[i]] == 1) {
				ans = min(ans, a[i]);
				if(a[i] == ans) d = i;
			}
		}

		if(ans == INT_MAX) cout << -1 << endl;
		else cout << d << endl;

	}		
	return 0;
}

