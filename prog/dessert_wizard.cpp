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
	cin >> t;
	while(t--) {
		int n;
		cin >>n;
		vector <int> a(n);
		int mi = INT_MAX, ma = INT_MIN;
		for(int i = 0; i < n; i++) {cin >>a[i]; mi = min(mi, a[i]);ma = max(ma, a[i]);}

		int sum[2][n + 10];
		int diff[2][n + 10];
		for(int i = 0; i <= n + 8; i++) {
			sum[0][i] = sum[1][i] = diff[0][i] = diff[0][i] = 0;
		}

		sum[1][0] = a[0];

		for(int i = 1; i < n; i++) {
			sum[0][i] = max(sum[0][i - 1], sum[1][i - 1]);
			sum[1][i] = max(sum[1][i - 1] + a[i], a[i]);
		}

		if(max(sum[0][0], sum[0][1]) == 0) sum[0][0] = sum[0][1] = ma;


		for(int i = n - 2; i >= 0; i--) {
			diff[0][i] = min(diff[0][i - 1])
		}  

	}		
	return 0;
}

