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

	int n;cin >> n;
	vector <pair<int, int> > a(n);
    
	int k, l, m;
	for(int i = 0; i < n; i++) {
		cin >> k >> l >> m;
		a[i] = mp(l+m, k);
	}

	sort(all(a));

	//int l = 0;
	int fin = 0;
    l = 0;
	for(int i = n - 1; i >= 0; i--) {
		fin = max(fin, l+a[i].fr + a[i].sc);
		l += a[i].sc;
	}

	cout << fin << endl;


	return 0;
}

