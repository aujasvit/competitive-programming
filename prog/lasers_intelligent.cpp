#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()
int n, xi, yi, xf, yf;
pii a[maxn];
map <int, vector <int, int> > row, col;
set <int> r, c;
map<pii,int> f;
int visited[maxn] = {0};
/*
	f[i][j] = 0 -->  horizontally
	f[i][j] = 1 --> vertically
*/



void make_graph() {
	//make graph using some scammy shitty programmin
	//tiresome
	for(set <int>:: iterator it = r.begin(); it != r.end(); it++) {
		int dodo = *it;
		vector <int> curr = row[dodo];
		sort(all(curr));

		for(int i = 1; i < curr.size() ;i++) {
			graph[curr[i]].pb(curr[i - 1]);
			graph[curr[i - 1]].pb(curr[i]);
			f[mp(curr[i],curr[i - 1])] = 0;
			f[mp(curr[i - 1], curr[i])] = 0;
		}


	}

	for(set <int>:: iterator it = c.begin(); it != c.end(); it++) {
		int dodo = *it;
		vector <int> curr = col[dodo];
		sort(all(curr));
		for(int i = 1; i < curr.size(); i++) {
			graph[curr[i]].pb(curr[i - 1]);
			graph[curr[i - 1]].pb(curr[i]);
			f[mp(curr[i],curr[i - 1])] = 1;
			f[mp(curr[i - 1], curr[i])] = 1;
		}
	}


}
//-1 --> not possible
int ans(int root = 0, bool hor) {
	it(root == n + 1) {
		return 0;
	}

	int cmin = INT_MAX;
	for(auto i:graph[root]) {
		if(visited[i]) continue;
		visited[i] = 
		int curr = f[mp(root, i)];
		if(curr == 0) {
			//hor
			int k = ans(i, true);
			if(k != -1) {
				if(!hor)k++;

				cmin = min(cmin, k);
			}
		} else {
			//ver
			int k = ans(i, false);
			if(k != -1) {
				if(hor)k++;
				cmin = min(cmin, k);
			}
		}


	}

	if(cmin == INT_MAX) return -1;

	return cmin;
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> xi >> yi >> xf >> yf;
	int k, l;
	for(int i = 1; i <= n; i++) {
		cin >> k >> l;
		row[k].pb(l);
		r.insert(k);
		row[l].pb(k);
		c.insert(k);
		a[i] = mp(k,l);
	}


	return 0;
}

