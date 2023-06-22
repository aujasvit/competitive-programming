//Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=863

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int n, k, a[10009], dp[10009][1009];//dp[n][k]

int ma;

int ans(int i, int d) {
	if(i > n) return 0;

	if(d > k) return ma * k;
	
	if(dp[i][d] != -1) return dp[i][d];
	
	if(d == 1) {
		ma = a[i];
	}

	//if(dp[i][d] != -1) return dp[i][d];
    
	

	ma = max(ma, a[i]);


	int macurr = ma;

	int l = ans(i + 1, d + 1);
    

	int f = (d * macurr);
	f = f + ans(i + 1, 1);
	dp[i][d] = max(f,l);
	return max(f, l);
}


signed main() {
		freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= k; j++) {
			dp[i][j] = -1;	
		}
	}
	cout << ans(1, 1);
		return 0;
}

