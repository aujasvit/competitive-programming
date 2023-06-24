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
	vector <int> a(n);

	for(int i = 0; i <n; i++) cin >> a[i];
	vector <int> dp(n);

	for(int i = 0; i< n ;i++) {
		dp[i] = a[i] + i + 1;
	}

	
	return 0;
}

