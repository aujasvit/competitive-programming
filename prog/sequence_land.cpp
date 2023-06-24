#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()
	int n, k;
vector <int> graph[310];
vector <vector <int> > a(310);
int ans = 0;
int visited[310];
void dfs(int curr) {
	if(visited[curr]) return;
	visited[curr] = 1;

	ans++;
	for(int i = 0; i < a[curr].size(); i++) {
		dfs(a[curr][i]);
	}
}



void makegraph() {
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			int com = 0;
			for(int k = 0; k < a[i].size(); k++) {
				if(a[j].binary_search(a[i][k]) ) {
					com++;
				}

			}
			if(com >= k) {
				graph[i].pb(j);graph[j].pb(i);
			}
		}
	}
}



signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin >> n >> k;
	
	for(int i = 1; i <= n; i++) {
		int p; cin >> p; a[i].resize(p);
		for(int j = 0; j < p; j++)cin >> a[i][j];
		sort(all(a[i]));
		visited[i] = 0;
	}

	makegraph();
	dfs(1);
	cout << ans - 1 << endl;
	


	return 0;
}

