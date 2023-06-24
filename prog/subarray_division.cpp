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
	int a[n + 2];
	for(int i = 1; i <= n; i++) cin >> a[i];
	int prefsum[n + 2];
	prefsum[0] = 0;
	for(int i = 1; i <= n; i++) prefsum[i] = prefsum[i - 1] + a[i];
	for(int i = 1; i <= n; i++) prefsum[i] %= n;
	map <int, int> freq;
	freq[0] = 1;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += freq[prefsum[i]];
		freq[prefsum[i]]++;
	}
	cout << ans << endl;
	return 0;
}

