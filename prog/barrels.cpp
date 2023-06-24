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
		for(int i = 0; i < n; i++) cin >> a[i];

		sort(all(a));

		for(int i = n - 2, j = 0; i >= 0 and j < curr; i--, j++) {
			a[n - 1] += a[i];j++;
		}
		cout << a[n - 1] - 0 << endl;
	}		
	return 0;
}

