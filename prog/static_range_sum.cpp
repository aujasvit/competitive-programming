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
	int n, q;
	cin >> n >> q;
	int a[n + 2];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(i != 0) a[i] += a[i - 1];
	}		
	for(int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;
		if(l == 0) {
			cout << a[r - 1] << endl;
		} else {
			cout << a[r - 1] - a[l - 1] << endl;
		}
	}
	return 0;
}

