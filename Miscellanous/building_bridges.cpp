#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int k = 0;
vector <int> ans;
bool visited[100006];
vector <int> graph[100005];

void dfs(int curr) {
	if(visited[curr]) {
		return;
	}

	visited[curr] = 1;
	for(int i = 0; i < graph[curr].size(); i++) {
		dfs(graph[curr][i]);
	}
	
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	

	int n, m;
	cin >> n >> m;

	for(int i = 0; i <= n; i++)  visited[i] = 0;

	for(int i = 0; i < m; i++) {
		int k, l;
		cin >> k >> l;

		graph[k].pb(l); graph[l].pb(k);
	}

	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			ans.pb(i);
			dfs(i);
		}
	}

	cout << ans.size() - 1 << endl;
	for(int i = 0; i < ans.size() - 1; i++) {
		cout << ans[i] << " " << ans[i + 1] << endl;;
	}

	
	return 0;
}

