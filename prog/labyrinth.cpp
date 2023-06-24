#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.fu()
int start, fu;
int visited[1000008];
vector<int> graph[1000008];
int n, m;
void bfs() {
	int dp[1000008];
	for(int i = 1; i <= 1000000; i++) visited[i] = -1;
	int curr = start;
	queue <int> dodo;
	dodo.push(start);
	visited[start] = 0;
	while(!dodo.empty()) {
		curr = dodo.front();
		dodo.pop();

		for(auto i:graph[curr]) {
			if(visited[i] != -1) continue;
			dp[i] = curr;
			visited[i] = visited[curr] + 1;
			dodo.push(i);
		}

	}

	if(visited[fu] == -1) {
		cout << "NO" << endl;
		return ;
	}
	
	cout << "YES" << endl;
	cout << visited[fu] << endl;
	vector <int> path;
	int i = fu;
	
	while(i != start) {
	    path.pb(i);
	    i = dp[i];
	} 
	path.pb(start);
	for(int i = path.size() - 1; i > 0; i--) {
	    int s = path[i], e = path[i - 1];
	    if(e - s == 1) cout << "R";
	    else if(s - e == 1) cout << "L";
	    else if(e - s == m) cout << "D";
	    else if(s - e == m) cout << "U";
	}
	cout << endl;


}

void makegraph() {
	cin >> n >> m;
	vector <string> grid(n + 1);

	for(int i = 1; i <= n; i++) {
		cin >> grid[i];

	}

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < m; j++) {
			int curr = (i - 1)*m + j + 1;
			string dodo = grid[i];
			if(dodo[j] == '#') continue;
			if(dodo[j] == 'A')start = curr;
			if(dodo[j] == 'B')fu = curr;

			if(i > 1) {
				if(grid[i - 1][j] != '#')graph[curr].pb(curr - m);
			}

			if(i < n) {
				if(grid[i + 1][j] != '#')graph[curr].pb(curr + m);				
			}

			if(j > 0) {
				if(grid[i][j - 1] != '#')graph[curr].pb(curr - 1);
			}

			if(j < m - 1) {
				if(grid[i][j + 1] != '#') graph[curr].pb(curr + 1);
			}
		}

	}

}


signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	makegraph();
	
	bfs();
	return 0;
}

