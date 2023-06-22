//Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=861

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int n, m, k;
vector <pii> graph[50005];
vector <pii> food;
int dp[50005];
void fill() {
	for(int i = 1; i < n; i++) dp[i] = INT_MAX;

	bool visited[n + 5] = {0};
	dp[n] = 0;
	priority_queue<pii> q;
	q.push(mp(0,n));
	while(!q.empty()) {
		pii curr = q.top(); q.pop();
		if(visited[curr.sc]) continue;

		visited[curr.sc] = 1;

		for(int i = 0; i < graph[curr.sc].size(); i++) {
			pii dodo = graph[curr.sc][i];
			if(dp[dodo.fr] > dp[curr.sc] + dodo.sc) {
				dp[dodo.fr] = dp[curr.sc] + dodo.sc;
				q.push(mp(-1*dp[dodo.fr], dodo.fr));
			}
		}
	}
}


void ans() {

	fill();
	priority_queue<pii> q;
	
	int fin[n + 5];
	bool visited[n + 5] = {0};
	for(int i = 1; i <= n; i++) {
		fin[i] = INT_MAX;

	}
	for(int i = 0; i < food.size(); i++) {
		fin[food[i].fr] = dp[food[i].fr] - food[i].sc;
		q.push(mp(-1*(dp[food[i].fr] - food[i].sc), food[i].fr));
	}
	while(!q.empty()) {
		pii curr = q.top();q.pop();
		if(visited[curr.sc]) continue;
		visited[curr.sc] = 1;
		for(int i = 0; i < graph[curr.sc].size(); i++) {
			pii dodo = graph[curr.sc][i];
			if(fin[dodo.fr] > fin[curr.sc] + dodo.sc) {
				fin[dodo.fr] = fin[curr.sc] + dodo.sc;
				q.push(mp(-1*fin[dodo.fr], dodo.fr));
			}
		}
	}
	
	for(int i = 1; i < n; i++) {
		if(fin[i] <= dp[i]) cout << 1 << endl;
		else cout << 0 << endl;
	}
}

signed main() {
	freopen("dining.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("dining.out", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		int al,be, ga;
		cin >> al >> be >> ga;
		graph[al].pb(mp(be,ga));
		graph[be].pb(mp(al,ga));
	} 

	for(int i = 0; i < k ; i++){
		int al,be;
		cin >> al >> be;
		food.pb(mp(al,be));
	}
	ans();
	return 0;
}