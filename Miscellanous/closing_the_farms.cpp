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
int order[100005];

void dfs(int curr) {
	if(visited[curr]) return;

	visited[curr] = 1;

	for(int i = 0; i < graph[curr].size(); i++) {
		dfs(graph[curr][i]);
	}
}

signed main() {
	freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int k, l;
	for(int i = 1; i <= n; i++) visited[i] = 0;

	for(int i = 0; i < m; i++) {
		cin >> k >> l; 
		graph[k].pb(l);graph[l].pb(k);	
	}
	
	vector <int> fu;
	k = 0;
	for(int i = 1; i <= n; i++) {
		
		for(int i = 1; i <= n; i++) visited[i] = 0;
		fu.pb(k);
		sort(all(fu));
		for(int j = 0; j < fu.size(); j++) {
			visited[fu[j]] = 1;
		}
		//visited[k] = 1;
		//vector <int> dodo = visited[k];
		graph[k].clear();
		bool d = false;
		string ans = "YES";
		for(int j = 1; j <= n; j++) {
			if(!visited[j]) {
				if(d) {
					ans = "NO";
					break;
				} else {
					d = true;
					dfs(j);
				}
			}
		}
		cin >> k;
		cout << ans << endl;
	}	



	return 0;
}

