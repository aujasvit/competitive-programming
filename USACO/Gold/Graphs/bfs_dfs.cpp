//Problem Link:https://csacademy.com/contest/archive/task/bfs-dfs

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n; cin >> n;
	vector <int> bfs(n + 1), dfs(n + 1);
	for(int i = 1; i <= n; i++) cin >> bfs[i];

	for(int i = 1; i <= n; i++) cin >> dfs[i];

	vector <int> graph[n + 1];

	cout << 2*n - 2 << endl;

	int c1 = bfs[1];
	for(int i = 2; i <= n; i++) {
		cout << c1 << " " << bfs[i] << endl;
	}

	for(int i = 2; i <= n; i++) {
		cout << dfs[i] << " " << dfs[i - 1] << endl;
	}



	return 0;
}

