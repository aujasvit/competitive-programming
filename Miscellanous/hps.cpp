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
int a[maxn];
int dp[maxn][4];

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	map <string, int> dict;

	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		a[i] = dict[s];
	}

	dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= 3; j++) dp[i][j] = dp[i-1][j];

		dp[i][a[i]]++;
	}


	for(int i = 1; i <= n; i++) {
		
	}


	return 0;
}

