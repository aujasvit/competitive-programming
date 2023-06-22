//Problem Link: https://cses.fi/problemset/task/1667

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
vector <int> graph[100005];
int visited[100005];
int dp[100005];

void bfs() {
	int curr = 1;
	queue <int> dodo;
	dodo.push(1);
	visited[1] = 0;
	while(!dodo.empty()) {
		curr = dodo.front();
		dodo.pop();

		for(auto i:graph[curr]) {
			if(visited[i] != -1) continue;
			dp[i] = curr;
			visited[i] = visited[curr] + 1;
			dodo.push(i);
		}

	}

	if(visited[n] == -1) {
		cout << "IMPOSSIBLE" << endl;
		return ;
	}

	cout << visited[n]+ 1 << endl;
	vector <int> path;
	int i = n;
	
	while(i != 1) {
	    path.pb(i);
	    i = dp[i];
	} 
	path.pb(1);
	for(int i = path.size() - 1; i >= 0; i--) {
	    cout << path[i] << " ";
	}
	cout << endl;


}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	int k, l;
	for(int i = 1; i <= m; i++) {
		cin >> k >> l;
		graph[k].pb(l);graph[l].pb(k);
	}

	for(int i = 1; i <= n; i++) visited[i] = -1;
    bfs();
	return 0;
}

