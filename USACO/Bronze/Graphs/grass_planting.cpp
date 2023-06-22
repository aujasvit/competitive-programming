//Problem statement: http://www.usaco.org/index.php?page=viewproblem2&cpid=894

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair <int,int>
#define fr first
#define sc second


signed main() {
	// freopen("planting.in", "r", stdin);
	// freopen("planting.out", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	

	int n, m;
	cin >> n;
	m = n - 1;
	vector <int> graph[n + 1];
	for(int i = 1; i <= n; i++) graph[i].clear();

	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	int ans = 0;

	for(int i = 1; i <= n; i++) {
		int temp = 1 + graph[i].size();
		// for(auto j:graph[i]) {
		// 	temp += graph[j].size() - 1;
		// }

		ans = max(ans, temp);
	}

	cout << ans << endl;


}