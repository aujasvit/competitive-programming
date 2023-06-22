//Problem Link: https://cses.fi/problemset/task/1679

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()
 
int state[100007] = {0};
vector <int> toposort;
int n, m;
bool pos = true;
vector <int> graph[100007];
 
void dfs(int curr) {
	if(state[curr] == 1) {
		pos = false;
		return;
	}
 
	if(state[curr] == 2) return;
 
	state[curr] = 1;
 
	for(auto i:graph[curr]) {
		dfs(i);
	}
    state[curr] = 2;
	toposort.pb(curr);
}
 
 
void fill() {
	for(int i = 1; i <= n; i++) {
		if(state[i] == 0) {
			dfs(i);
			if(!pos) {
				cout << "IMPOSSIBLE" << endl;
				return;
			}
		}
	}
 
	for(int i = toposort.size() - 1; i >= 0; i--) {
		cout << toposort[i] << " ";
	}
}
 
 
signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int k,l;
		cin >> k >> l;
		graph[k].pb(l);
	}
 
	fill();
	return 0;
}