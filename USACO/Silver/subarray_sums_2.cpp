//Problem Link: https://cses.fi/problemset/task/1661

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
	int n,x;
	cin >> n >> x;
	int a[n + 2];
	for(int i = 1; i <= n; i++) cin >> a[i];
 
	int prefsum[n + 2];
	prefsum[0] = 0;
	for(int i = 1; i <= n; i++) prefsum[i] = prefsum[i - 1] + a[i];
 
	map <int, int> freq;
	int ans = 0;
	freq[0] = 1;
	for(int i = 1; i <= n; i++) {
		int tofind = prefsum[i] - x;
		ans += freq[tofind];
		freq[prefsum[i]] += 1;
	}
 
	cout << ans << endl;
 
	return 0;
}