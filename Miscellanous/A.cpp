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
		int n;
		cin >> n;
		//a ^ 2 = 2c - 1
		float f = sqrt( (2 * n) - 1);
		int d = floor(f);

		if(d < 3) {
			cout << 0 << endl;
			continue;
		}

		if(d % 2 == 0) {
			d--;
		}

		int dodo = (d - 3)/2 + 1;
		cout << dodo << endl;
		//cout << d << endl;
	}
	return 0;
}

