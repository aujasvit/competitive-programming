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
vector <pii> graph[100005];
int dp[100005];

void ans() {
	dp[1] = 0;
	for(int i = 2; i <= n; i++) {
		dp[i] = 9999900000000010 ;
	}

	priority_queue <pii> curr;
	curr.push(make_pair(0,1));
	int visited[n + 10] = {0};

	while(!curr.empty()) {
		pii dodo = curr.top();
		curr.pop();
		if(visited[dodo.sc]) {
			continue;
		}
		visited[dodo.sc] = 1;
		
		for(int i = 0; i < graph[dodo.sc].size(); i++) {
			pii fofo = graph[dodo.sc][i];
			if(dp[fofo.fr] > dp[dodo.sc] + fofo.sc) {
				dp[fofo.fr] = dp[dodo.sc] + fofo.sc;
				curr.push(mp(-dp[fofo.fr], fofo.fr));
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int k, l, dodo;
		cin >> k >> l >> dodo;
		graph[k].pb(mp(l,dodo));
		
	}

	ans();
	return 0;
}

