#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int n, k;
vector <int> graph[100006];

bool visited[100006] = {0};
int ans = 0;

void visit(int curr) {
	bool d = true;
	visited[curr] = true;
	for(auto i:graph[curr]) {
		if(visited[i]) continue;
		visit(i);
		d = false;
	}

	if(d) ans++;
}

void make_graph() {
	int k, l;
	for(int i = 0; i < n - 1; i++) {

		cin >> k >> l;
	graph[k].pb(l);
	graph[l].pb(k);

	}




}	

signed main() {

	freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> k;
	make_graph();
	visit(k);

	cout << ans << endl;

	return 0;
}

