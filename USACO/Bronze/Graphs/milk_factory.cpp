//Problem link: http://www.usaco.org/index.php?page=viewproblem2&cpid=940

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair <int,int>
#define fr first
#define sc second


signed main() {
	// freopen("factory.in", "r", stdin);
	// freopen("factory.out", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	

	int n, m;
	cin >> n;
	m = n - 1;
	vector <int> graph[n + 1];
	for(int i = 1; i <= n; i++) graph[i].clear();

	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].pb(v);
	}
	for(int i = 1; i <= n ;i++) {
		int reached[n + 1] = {0};
		reached[i] = 1;
		
		while(true) {
			int changed = 0;
			for(int j = 1; j <= n; j++) {
				if(i == j)continue;
				for(auto k:graph[j]) {
					if(reached[k] && !reached[j]) {
						reached[j] = 1;
						changed++;
						break;
					}
				}
			}
			if(changed == 0) break;
		}

		bool d = true;
		for(int j = 1; j <= n; j++) {
			if(!reached[j]) d = false;
		}

		if(d) {
			cout << i << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;

}