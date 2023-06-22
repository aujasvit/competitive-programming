//Problem Link: https://cses.fi/problemset/task/1666/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair <int,int>
#define fr first
#define sc second
 
bool visited[100005] = {0};
vector <int> graph[100005];
 
void dfs(int curr) {
	if(visited[curr]) return;
 
	visited[curr] = 1;
 
	for(auto j:graph[curr]) dfs(j);
}
 
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("in.in", "r", stdin);
	// freopen("out.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		graph[i].clear();
	}
 
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v; 
		graph[u].pb(v);
		graph[v].pb(u);
	}
	int connected = 0;
	vector <pii> roads;
	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			connected++;
			dfs(i);
			if(i != 1) roads.pb(mp(1,i));
		}
	}
 
	cout << connected - 1 << endl;
	for(auto j:roads) {
		cout << j.fr << " " << j.sc << endl;
	}
 
}