#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int r,c,n;
pii a[100009];
map <pii, int> visited;
vector <int> row[1000001];
//
int dfs(int r, int c) {

	if(visited[r][c]) return 0;

	visited[mp(r,c)] = 1;
	int k = 0;
	int l = 4;
	if(binary_search(row[r].begin(), row[r].end(), c + 1)) {
		l--;
		k += dfs(r, c + 1);
	}

	if(binary_search(row[r].begin(), row[r].end(), c - 1)) {
		l--;
		k += dfs(r, c - 1);
	}


	if(binary_search(row[r - 1].begin(), row[r - 1].end(), c)) {
		l--;
		k += dfs(r - 1, c);
	}


	if(binary_search(row[r + 1].begin(), row[r + 1].end(), c)) {
		l--;
		k += dfs(r + 1, c);
	}

	k += l;

	return k;

}
signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> r >> c >> n;
	for(int i = 1; i <= n; i++) {
		int k, l;
		cin >> k >> l;
		a[i] = mp(k,l);
		row[k].pb(l); col[l].pb(k);
	}

	for(int i = 1; i <= r; i++) {
		sort(all(row[i]));
	}

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(visited[a[i]]  == 0) {
			ans = max(dfs(a[i].fr, a[i].sc), ans);
		}
	}

	cout << ans << endl;
	return 0;
}

