//Problem Link: https://codeforces.com/contest/279/problem/B

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
	int n, t;
	cin>> n >> t;

	int a[n + 1] = {0};
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) a[i] += a[i - 1];
	int l = 1, r = 1;
	while(r < n and a[r + 1] - a[l - 1] <= t) r++;
	int ans = r - l + 1;

	if(a[1] > t) ans = 0;

	while(r <= n and l <= n) {
		l++;
		while(r < n and a[r + 1] - a[l - 1] <= t) r++;
		
		ans = max(ans, r - l + 1);
	}

	cout << ans << endl;

	return 0;
}

