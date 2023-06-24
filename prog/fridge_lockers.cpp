#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()
vector <pair <int, int> > a;

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int mi = INT_MAX, d;
		a.clear();
		for(int i =0 ; i < n; i++) {
			cin >> d;
			a.pb(mp(d,i + 1));
		}

		sort(all(a));

		for(int i = 1; i <= n; i++) {
			if(i == a[0].second())
		}


	}		
	return 0;
}

