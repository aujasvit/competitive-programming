#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int n, m,q;
int graph[510][510];
int dp[500][500];

void fy() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) {
				dp[i][j] = 0;
			} else if(graph[i][j]) {
				dp[i][j] = graph[i][j];
			} else {
				dp[i][j] = 10000000000000;
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n ;j++) {
			for(int k = 1; k <= n; k++) {
				dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
			}
		}
	}


}


signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m >> q;
	int a, b, c;

	for(int i = 1; i <= n ;i++) {
		for(int j = 1; j <= n; j++) {
			graph[i][j] = 0;
		}
	}

	for(int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		if(graph[a][b] != 0) {
			graph[a][b] = graph[b][a] = min(graph[a][b], c);
			continue;
		}
		graph[a][b] = graph[b][a] = c;
	}
	fy();

	for(int i = 1; i <= q; i++) {
		cin >> a >> b;
		int k = dp[a][b];
		if(k == 10000000000000) cout << -1 << endl;
		else cout << k << endl;
	}
	return 0;
}

