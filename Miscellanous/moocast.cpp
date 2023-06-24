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


int dodo = 0;

void dfs(int curr) {
	if(visited[curr]) return;
	
	visited[curr] = 1;
	dodo++;
	for(int i = 0; i < graph[curr].size(); i++) {
		dfs(graph[curr][i]);
	}
}


signed main() {
	freopen("moocast.in", "r", stdin);
   freopen("moocast.out", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int n;
	cin >> n;
	vector <pii> a;
	vector <int> pi;
	a.pb(mp(0,0));pi.pb(0);
	for(int i = 0; i < n;i++) {
		int x, y, p;
		cin >> x >> y >> p;
		a.pb(mp(x,y));
		pi.pb(p);

	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <=n; j++) {
			if(i ==j) continue;
			int fu = a[i].first - a[j].first, pu = a[i].second - a[j].second;
			float dis = pow((fu*fu) + (pu*pu), 0.5);
		//	cout << i << " " << j << " " << fu* fu << " " << pu*pu <<  endl;
			if(dis <= pi[i]) {
				graph[i].pb(j);
			}

		}
	}	
	int fin = 0;
	for(int i = 1; i <= n; i++) {
	    for(int j = 1; j <= n; j++)visited[j] = 0;
		dodo = 0;
		dfs(i);
		fin = max(fin, dodo);
	} 

	cout << fin << endl;
	return 0;
}

