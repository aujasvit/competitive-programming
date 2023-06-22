//Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=815

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int n;
int a[110];
int dp[110][110][110];
//should be dodo at pos curr
int ans(int curr, int left, int dodo) {
	if(curr > n) {
		if(left != 0) return INT_MAX;
		else return 0;
	}
	if(dp[curr][left][dodo] != -1) return dp[curr][left][dodo];
	int p = 0;
	if(left == 0) {
		if(a[curr] != dodo) {
			p++;
		}
		p += ans(curr + 1, left, dodo + 1);
	} else {
		int a1 = 0;
		if(a[curr] != dodo)a1++;
		a1 += ans(curr + 1, left, dodo + 1);

		int a2 = 0;
		if(a[curr] != 0) a2++;
		a2 += ans(curr + 1, left - 1, 1);

		p = min(a1,a2);
	}
	dp[curr][left][dodo] = p;
	return p;
}


signed main() {
	freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <=n ;i++) cin >> a[i];

	for(int i = 1; i <= n; i++) {
		for(int k = 0; k < 110; k++) {
			for(int l = 0; l < 110; l++) {
				for(int m = 0; m < 110; m++) {
					dp[k][l][m] = -1;
				}
			}
		}
		int a1 = 0;
		a1 += ans(2,i - 1, 1);
		if(a[1] != 0)a1++;
		cout << a1 << endl;
	}
	return 0;
}

