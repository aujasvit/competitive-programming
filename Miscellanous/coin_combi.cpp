

#include <iostream>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()
 
int dodo = 1000000007;
int a[105], dp[1000009];
signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, x;
	cin >> n >> x;
	//vector <int> a(n), dp(x + 1);
	for(int i = 0; i < n; i++) cin >> a[i];
	dp[0] = 1;
	for(int i = 1; i <= x; i++) {
		dp[i] = 0;
		for(int j = 0; j < n; j++) {
			if(i >= a[j]) {
				dp[i] += dp[i - a[j]];
				if(dp[i] >= dodo) dp[i] -= dodo;
				//dp[i] %= dodo;
			}
		}
	}
 
	cout << dp[x] << "\n";		
	return 0;
}