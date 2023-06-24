#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int a[maxn]
int n,k;
int ans(int l, int r) {
	if(l >= r) return 0;
	int fin = 0;
	for(int i = l; i <= r; i++) {
		if(a[i] == a[l] + k) {
			fin = max(fin, val[l] + val[r] + ans(l + 1, i - 1) + ans(i + 1, r));
		}
	}
	fin = max(fin, ans(l + 1, r));
	return fin;
}


signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];

	cout << ans(1, n) << endl;
	return 0;
}

