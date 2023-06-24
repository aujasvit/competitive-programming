#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int lis() {
	int dp[n + 2];

	for(int i = 1; i <= n; i++) {
		dp[i] = 1;
		for(int j = 1; j < i; j++) {
			if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	return dp[n];
}


int lis_nlogn() {
	
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
		
	return 0;
}

