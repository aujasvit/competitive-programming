#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int graph[235][235], dp[235][235];

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <=n; j++) {
			if(i == j) {graph[i][j] = 0;dp[i][j] = 0;}
			else {graph[i][j] = 100000000000; dp[i][j] = 100000000000;}
		}
	}
	
	int kodo, l;
	
	for(int i = 0; i < m; i++) {
		cin >> kodo >> l;
		cin >> graph[kodo][l];
		graph[l][kodo] = graph[kodo][l];
		dp[kodo][l] = dp[l][kodo] = graph[kodo][l];
	}
	
	for(int k = 1; k <= n; k++) {
	    for(int i = 1; i <= n; i++) {
	    	for(int j = 1; j <= n; j++) {//between i and j

				//if(k == i or k == j) continue;
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			
		}
	}
	
	
}

kodo = 0;
for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
        if(dp[i][j] == 100000000000) continue;
        kodo = max(kodo, dp[i][j]);
    }
}
cout << kodo << endl;

	return 0;
}

