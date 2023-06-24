#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int n, m, k;
vector <vector <int> > graph[1000007];
bool visited[1000007];
int mus[1000007];

int dfs(int curr) {
	if(visited[curr]) return 0;
	int fu = 0;
	visited[curr] = 1;
	for(auto i:graph[curr]) {
		fu += dfs(i);
	}
	fu += mus[curr];
	return fu;
}

int ans() {
	int count = 0;
	vector <int> dodo;
	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			int fu = dfs(i);
			dodo.pb(fu);
			count++;
		}
	}

	if(count <= k) return -1;

	int i = 0, j = dodo.size() - 1;

	int fin = 0;

	count = 0;
	while(count < k) {
		fin += dodo[j];
		count++;
		j--;
	}

	return fin;

}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t; cin >> t;
	while(t--) {
		cin >> n >> m >> k;
		for(int i = 1; i <= n; i++) {
			graph[i].clear();
			visited[i] = false;
		}
			for(int i = 1; i <= m; i++) {
				int k, l;
				cin >> k >> l;
				graph[k].pb(l); graph[l].pb(k);
			}
		for(int i = 1; i <= n; i++) cin >> mus[i];

		cout << ans() << endl;
		
	}	
	return 0;
}

