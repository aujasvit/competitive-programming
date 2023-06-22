//Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI1601

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()
vector <int> a, p;
vector <vector <int> > graph;

int ans = INT_MIN;
vector <int> vis;
int dfs(int curr) {
		if(vis[curr]) {
			return INT_MAX;
		}
		vis[curr] = true;

	int pres = INT_MAX - 100;
	for(int i = 0; i < graph[curr].size(); i++) {
			pres = min(pres, dfs(graph[curr][i]));
	}
	ans = max(ans, a[curr]- pres);
	return min(pres, a[curr]);

}



signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin >>n ;
	a.resize(n + 1);p.resize(n + 1);

	for(int i = 1; i <= n; i++) {
			cin >> a[i];
	}

	for(int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	graph.resize(n + 1);
	int head;
	for(int i = 1; i < n + 1; i++) {
		if(p[i] == -1) {
			head = i;
			continue;
		}

		graph[i].pb(p[i]);
		graph[p[i]].pb(i);
	}

	vis.resize(n + 1);
	for(int i = 1; i <= n; i++)vis[i] = 0;

	int f = dfs(head);

	cout << ans << endl;


	return 0;
}
