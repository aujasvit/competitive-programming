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
bool grid[1005][1005];
bool visited[1005][1005];

void travel(int r, int c) {
	if(r < 1 or r > n or c < 1 or c > m) return ;
	if(visited[r][c]) return ;
	if(grid[r][c] == 0) return ;

	visited[r][c] = 1;
	travel(r - 1,c) ;travel(r + 1, c) ;travel(r, c - 1) ; travel(r, c + 1);


}

void inp() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		string s;cin >> s;
		for(int j = 0; j < m; j++) {
			int k;
			if(s[j] == '#') k = 0;
			else k = 1;
			grid[i][j + 1] = k;
			visited[i][j + 1] = 0;
		}
	}
}

int fin() {
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(!visited[i][j] and grid[i][j]) {
				ans++;
				travel(i,j);
			}
		}
	}

	return ans;
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	inp();
	cout << fin() << endl;
	return 0;
}

