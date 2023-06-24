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
	int n;
	cin >> n;
	pair <int,int> a[400009];
	int d = 0;
	for(int i = 1; i <= n; i++) {
		int k, l;
		cin >> k >> l;
		a[d] = mp(k, 1);
		d++;
		a[d] = mp(l, -1);
		d++;
	}
	sort(a,a + d);
	int ans = 0, k = 0;
	for(int i = 0; i < d; i++) {
		if(a[i].sc == 1) {
			k++;
		} else {
			k--;
		}
		ans = max(ans,k);
	}

	cout << ans << endl;
	return 0;
}

