//Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI2001

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
vector <int> graph[100005];
bool visited[100005], visited2[100005], visited3[100005];


int dfs(int curr) {

	visited[curr] = 1;
	int a = 0;
	for(auto i:graph[curr]) {
		if(visited[i]) continue;
		a += dfs(i);
	}
	a++;
	return a;
	
}

int dfsmax(int curr) {
	visited2[curr] = 1;
	int a = 0;
	for(auto i:graph[curr]) {
		if(visited2[i]) continue;
		a = max(dfsmax(i), a);
	}
	a = max(a, curr);
	return a;
}

int dfsmin(int curr) {
	visited2[curr] = 1;
	int a = INT_MAX;
	for(auto i:graph[curr]) {
		if(visited2[i]) continue;
		a = min(a, dfsmin(i));
	}
	a = min(a, curr);
	return a;
}


int dodo(int curr, int fu = 0) {
	visited3[curr] = 1;
	int a = 0;
	for(auto i:graph[curr]) {
		if(visited3[i]) continue;
		a += dodo(i, fu + 1);
	}
	a += fu;
	return a;
}

void fu() {
	vector <int> odd,even;
	for(int i = 1; i <= n; i++) {
		if(visited[i]) continue;
		
		int f = dfs(i);

		if(f % 2 == 0) {
			even.pb(dfsmin(i));
		} else {
			odd.pb(dfsmax(i));
		}
	}

	int o,e;
	o = e = 0;
	for(auto i:odd) {
	   // cout << i << "even" << endl;
		o += dodo(i, 1);
	}
	for(auto i:even) {
	//    cout << i << "odd" << endl;
		e += dodo(i, 1);
	}

	cout << e << " " << o << endl;
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 1; i <= n; i++) {graph[i].clear(); visited[i] = 0;visited2[i] = visited3[i] = 0;}
		for(int i = 1; i <= m; i++) {
			int al, be;
			cin >> al >> be;
			graph[al].pb(be); graph[be].pb(al);
		}

		fu();


	}
	return 0;
}
