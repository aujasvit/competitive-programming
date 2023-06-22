//Problem link: http://www.usaco.org/index.php?page=viewproblem2&cpid=916

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair <int,int>
#define fr first
#define sc second

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("revegetate.in", "r", stdin);
	// freopen("revegetate.out", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	

	int n, m;
	cin >> n >> m;
// 	m = n - 1;
	vector <int> graph[n + 1];
	for(int i = 1; i <= n; i++) graph[i].clear();

	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	
	int color[n + 5] = {0};

	color[1] = 1;

	for(int i = 2; i <= n; i++) {
		int already[5] = {0};
		for(auto j:graph[i]) {
			already[color[j]]++;
		}

		for(int k = 1; k <= 4; k++) {
			if(!already[k]) {
				color[i] = k;
				break;
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		char c = color[i] + '1' - 1;
		cout << c;
	}
}