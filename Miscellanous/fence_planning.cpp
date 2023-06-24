#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

bool visited[100006];
vector <int> graph[100005];
vector <pii> a;
int miix = 0, maax = 0, miy = 0, may = 0;

void dfs(int curr) {
	if(visited[curr])return;
	visited[curr] = 1;
//	cout << curr << endl;


	miix = min(miix, a[curr].first);
	miy = min(miy, a[curr].second);
	maax = max(maax, a[curr].first);
	may = max(may, a[curr].second);

	for(int i = 0; i< graph[curr].size(); i++) {
		dfs(graph[curr][i]);
	}
}

signed main() {
	freopen("fenceplan.in", "r", stdin);
   freopen("fenceplan.out", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	int k, l;
	a.pb(mp(0,0));
	for(int i = 1; i <= n; i++) {
		cin >> k >> l;
		a.pb(mp(k, l));
		visited[i] = 0;
		graph[k].clear();
	}
//cout << a[7].first << " " << a[7].second << endl;
	for(int i = 0; i < m; i++) {
		cin >> k >> l;
		graph[k].pb(l); graph[l].pb(k);
	}
	int fin = INT_MAX;
	for(int i = 1; i <= n; i++) {
		miix = INT_MAX, miy = INT_MAX, maax = INT_MIN, may = INT_MIN;
		if(!visited[i]) {
			dfs(i);
			int l1 = abs(miix - maax);
			int l2 = abs(miy - may);
			fin = min(fin, 2*(l1 + l2));
		}
	}

	cout << fin << endl;


			
	return 0;
}

