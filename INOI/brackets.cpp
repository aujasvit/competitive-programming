//Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI1602

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int a[1000], val[1000];
int n,k;
int dp[1000][1000];
int ans(int l, int r) {
	if(l >= r) return 0;
	if(l > n) return 0;
	if(r > n ) return 0;
	if(dp[l][r] != -1) return dp[l][r];
	int fin = 0;
	for(int i = l; i <= r; i++) {
		if(a[i] == a[l] + k) {
			fin = max(fin, val[l] + val[i] + ans(l + 1, i - 1) + ans(i + 1, r));
		}
	}
	fin = max(fin, ans(l + 1, r));
	dp[l][r] = fin;
	return fin;
}


signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> val[i];
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++) {
	    for(int j = 1; j <= n; j++) {
	        dp[i][j] = -1;
	    }
	}

	cout << ans(1, n) << endl;
	return 0;
}
