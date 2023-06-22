//Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI1302

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()


vector <vector <int> > graph;


int dodo(vector <int> a, vector <int> b) {
	int com = 0;
	for(int i = 0; i < a.size(); i++) {
		if(binary_search(b.begin(),b.end(),a[i]) ) {
			com++;
		}
	}

	return com;
}

vector <int> f;
int ans = 0;

void dfs(int curr) {
	if(f[curr]) {
		return;
	}
	f[curr] = true;
	ans++;
	for(int i = 0; i < graph[curr].size(); i++) {
		dfs(graph[curr][i]);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector <vector <int> > a(n + 1);
	int p, temp;
	for(int i = 1;i <= n; i++) {
		cin >> p;
		for(int j = 0; j < p; j++) {
			cin >> temp;
			a[i].pb(temp);
		}
		sort(a[i].begin(),a[i].end());
	}

	graph.resize(n + 1);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(dodo(a[i],a[j]) >= k) {
					graph[i].pb(j);
					graph[j].pb(i);
				}
			}
		}

	f.resize(n + 1, 0);
	
	dfs(1);
	cout << ans << endl;

	return 0;
}
