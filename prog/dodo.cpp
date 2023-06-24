#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int grid[1100][1100];
int is(int row, int col){
    
    
    if(row < 0 or col < 0) return 0;
	if(!grid[row][col]) return 0;
	int dodo = 0;
	if(row > 0 and grid[row - 1][col])dodo++;
	if(grid[row + 1][col])dodo++;
	if(col > 0 and grid[row][col - 1])dodo++;
	if(grid[row][col + 1])dodo++;

	if(dodo==4) return -1;
	if(dodo == 3) return 1;
	return 0;
}

int fu(int row, int col){
	int dodo = 0;
	if(row > 0 and grid[row - 1][col])dodo++;
	if(grid[row + 1][col])dodo++;
	if(col > 0 and grid[row][col - 1])dodo++;
	if(grid[row][col + 1])dodo++;

	if(dodo==4) return 0;
	if(dodo == 3) return 1;
	return 0;
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i <= 1000; i++) {
		for(int j = 0; j <= 1000; j++) {
			grid[i][j] = 0;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int r,c;
		cin >> r >> c;
		grid[r][c] = 1;
		ans += fu(r,c) + is(r - 1,c) + is(r + 1, c) + is(r, c-1) + is(r, c+ 1);
	cout << ans << endl;
	
	    
	}
	return 0;
}

