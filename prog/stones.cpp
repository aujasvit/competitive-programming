#include <bits/stdc++.h>
upsing namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int a[1050]
int dp[100009]
signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n;i++) cin >> a[i];
	dp[0] = 0;
	for(int i = 1; i <= k; i++) {
		dp[i] = 0;
		for(int j = 0; j < n; j++) {
			if(a[j] <= i) {
				dp[i] = dp[i] or dp[i - a[j]];
			}
		}
	}

	if(dp[k]) {
		cout << "First" << endl;
	} else {
		cout << "Second" << endl;
	}
	//this dp is strictly wrt first
	//1 --> win
	//0 --> lose
	//this is if first has the chance

	dp[0] = false;
	
	return 0;
}

