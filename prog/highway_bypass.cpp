#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()
int r,c,d;
vector <int> graph;
signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> r >> c >> d;
	graph.resize(r);
	vector <vector <int> > dp(c);
	for(int i = 0; i < r; i++) {
		graph[i].resize(c);
		dp[i].resize(c);
		for(int j = 0; j < c; j++) {
			cin >> graph[i][j];
			if(graph[i][j] == 0) {
				dp[i][j] = 0;continue;
			}
			dp[i][j] = -1;
		}
	}


	bool d = true;

	for(int row = 0, col = 0; col < c; col++) {
		if(!d) {
			dp[i][j] = 0;
			continue;
		}
		if(graph[row][col] == 0) {
			d = false;
			dp[i][j] = 0;
			continue;
		}
		dp[i][j] = 1;
	}

	d = true;

	for(int row = 0, col = 0; row < r; row++) {
	if(!d) {
			dp[i][j] = 0;
			continue;
		}
		if(graph[row][col] == 0) {
			d = false;
			dp[i][j] = 0;
			continue;
		}
		dp[i][j] = 1;	
	}


	for(int row = 1; row < r; row++) {
		for(int col = 1; col < c; col++) {
			if(graph[row][col]) {
				dp[row][col] = dp[row][col - 1] + dp[row - 1][col]
			}
		}
	}


	return 0;
}

