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

pii values[100005];

vector <int> graph[100005];
int minx, maxx, miny, maxy;
int ans = INT_MAX;

int visited[100005] = {0};

void dfs(int curr) {
	minx = min(values[curr].fr, minx);
	maxx = max(maxx, values[curr].fr);
	miny = min(values[curr].sc, miny);
	maxy = max(values[curr].sc, maxy);
	visited[curr] = 1;
	for(auto i:graph[curr]) {
		if(visited[i]) continue;
		dfs(i);
	}
}

void driver() {
	for(int i = 1; i <= n; i++) {
		if(visited[i] == 0) {
			maxx = maxy = INT_MIN;
			minx = miny = INT_MAX;
			dfs(i);
			ans = min(ans, 2* (maxx + maxy - minx - miny));
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin  >> n >> m;

	for(int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		values[i] = mp(x,y);
	}

	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}

	driver();
	cout << ans << endl;

	return 0;
}

