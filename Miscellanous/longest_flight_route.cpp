#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int n,m;
vector <int> graph[100005];
vector <int> toposort;
int status[100005];

void topo(int curr) {
    
	if(status[curr] == 2) return;

	if(status[curr] == 1) return;

	status[curr] = 1;

	for(int i = 0; i < graph[curr].size(); i++) {
		topo(graph[curr][i]);
	}

	toposort.pb(curr);
	status[curr] = 2;
}


void engine() {
	for(int i = 1; i <= n; i++) {
		if(status[i] == 0)topo(i);
	}
}


void ans() {
    int dp[n + 2];
	bool d = false;
	int parent[n + 2] = {0};
	for(int i = 1; i <= n; i++)dp[i] = 0;
	for(int i = 0; i <= toposort.size() - 1; i++) {
		if(toposort[i] == n) {
			d = true;
			dp[toposort[i]] = 1;
			continue;
		}
		
		if(d) {
			dp[toposort[i]] = 0;
			for(auto j: graph[toposort[i]]) {
				if(dp[j] > dp[toposort[i]]) {
					dp[toposort[i]] = dp[j];
					parent[toposort[i]] = j;
				}
				//dp[a[i]] = max(dp[a[i]],dp[j]);
			}
			dp[toposort[i]]++;
		}

	}
	if(dp[1] == 0) {
		cout << "IMPOSSIBLE" << endl;
		exit(0);
	}
	cout << dp[1] << endl;
	int k = 1;
	while(k != n) {
		cout << k << " ";
		k = parent[k];
	}
	cout << n << endl;
	exit(0);
}


signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int al,be;
		cin >> al >> be;
		graph[al].pb(be);
	}
	engine();
	//for(auto i:toposort)cout << i << " ";
		ans();
	    
	return 0;
}

