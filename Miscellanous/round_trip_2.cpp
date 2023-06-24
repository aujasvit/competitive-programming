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
int visited[100006] = {0};
vector <int> graph[100006];
int parent[100006];
bool d = false;

void fcuk(int curr, int par) {
	int i = curr;
	vector <int> ans;
	int k = 0;
	while(i != par) {
		ans.pb(i);
		i = parent[i];
		k++;
	}
	cout << k + 2 << endl;
	cout << par << " ";
	for(int j = ans.size() - 1; j >= 0; j--) {
		cout << ans[j] << " ";
	}
	d = true;
	cout << par << endl;
	exit(0);
}

void dfs(int curr) {

	visited[curr] = 1;

	for(auto i:graph[curr]) {
		if(visited[i] == 1) {
			fcuk(curr, i);
			break;
		}
		if(visited[curr] == 2) continue;
		parent[i] = curr;
		dfs(i);
	}
	visited[curr] = 2;

}

void drive() {
	for(int i = 1; i <= n and !d; i++) {
		if(visited[i] == 0) {
			dfs(i);
		}
	}
	
	if(d) return;
	
	cout << "IMPOSSIBLE" << endl;
}


signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;

	for(int i = 0; i < m; i++) {
		int al,be;
		cin >> al >> be;
		graph[al].pb(be);
	}
	drive();
	return 0;
}

