#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int n, m, t;
vector <int> graph[maxn];
vector <int> shortest[maxn];
int cows[maxn];
int dp[maxn];
map<int,int> freq;

void dj() {
	for(int i = 1; i <= n; i++) {
		dp[i] = INT_MAX;
	}
	bool visited[n + 5] = {0};
	priority_queue<pii> q;
	q.push(mp(0,1));
	dp[1] = 0;
	while(!q.empty()) {
		pii curr = q.top();q.pop();
		if(visited[curr.sc]) continue;
		visited[curr.sc] = 1;

		for(int i = 0; i < graph[curr.sc].size(); i++) {
			
			pii dodo = graph[curr.sc][i];
			

			if(dp[dodo.fr] > dp[curr.sc] + dodo.sc) {
				shortest[dodo.fr] = shortest[curr.sc];
				shortest[dodo.fr].pb(curr.sc);
				dp[dodo.fr] = dp[curr.sc] + dodo.sc;
				q.push(mp(-1*dp[dodo.fr], dodo.fr));
			}
		}	

	}
}

void fill() {
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < shortest[i].size(); i++) {
			freq[shortest[i][j]] += cows[i];
		}
	}
}


int ans() {
	for(int )
}




signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m >> t;
	for(int i = 1; i <= n; i++) cin>> cows[i];
	for(int i = 1; i <= m; i+) {
		int al,be,ga;
		cin >> al >> be >> ga;
		graph[al].pb(mp(be,ga));
		graph[be].pb(mp(al,ga));
	}
	return 0;
}

