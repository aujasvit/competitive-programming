#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()
int n, m;
vector <int> graph[2510];
int ans = INT_MAX;

int u1,u2;
int dp[2510] = {0};
int visited[2510] = {0};

void shortest() {
	for(int i = 1; i <= n; i++) {
		dp[i] = visited[i] = 0;
	} 

	int curr = u1;
	queue <int> f;
	f.push(curr);

	while(f.size()) {
		curr = f.front();
		f.pop();
		visited[curr] = true;

		for(auto i:graph[curr]) {
			if( (i == u1 and curr == u2) or (i == u2 and curr == u1) ) {
		//	    cout << "CLOWN" << endl;
			    continue;
			    
			}
			if(visited[i]) continue;
			f.push(i);
			dp[i] = dp[curr] + 1;
		}

	}

		if(dp[u2] >= 2)ans = min(ans,dp[u2]);
}



signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	int k, l;
	for(int i = 0; i < m; i++) {
		cin >> k >> l;
		graph[k].pb(l);
		graph[l].pb(k);
	}

	for(int i = 1; i <= n; i++) {
		for(auto k:graph[i]) {
			u1 = i; u2 = k;
			shortest();
		}
	}

	if(ans == INT_MAX) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans +  1 << "\n";
	return 0;
}

