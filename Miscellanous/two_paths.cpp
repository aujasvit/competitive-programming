#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int n, m, k;

int grid[1100][1100];
int prefix[1100][1100];
int dp[200][200][200];

int ans(int l1,int l2, int row) {
	if(row < 1) return 0;
	if(l1 < 1 or l2 > m) return INT_MIN;


	if(l2 <= l1) return INT_MIN;
	if(dp[l1][l2][row] != -1) return dp[l1][l2][row];

	int d1 = ans(l1, l2, row - 1), d2 = ans(l1, l2 - 1, row - 1), d3 = ans(l1 - 1, l2, row - 1), d4 = ans(l1 - 1, l2 - 1, row - 1);
	dp[l1][l2][row] = max({d1,d2,d3,d4}) + prefix[row][l2] - prefix[row][l1 - 1];
	return max({d1,d2,d3,d4}) + prefix[row][l2] - prefix[row][l1 - 1];
}

int row;

int ma(int row, int curr) {
	if(row < 1) return 0;

	if(curr > )
}


int fu() {
	int fin = INT_MIN;
	for(int i = 1; i <= n - 1; i++) {
		for(int j = i + k + 1; j <= m; j++) {
			fin = max(fin, ans(i, j, n));
		}
	}
	return fin;
}

void fill() {
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			
			if(j == 0) {
				prefix[i][j] = 0;
				continue;
			}
			prefix[i][j] = prefix[i][j - 1] + grid[i][j];
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;cin >> t;
	while(t--) {
		cin >> n >> m >> k;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> grid[i][j];
			}
		}

		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= m; j++) {
				for(int jj = 1; jj <= n; jj++) dp[i][j][jj] = -1;
			}
		}

        fill();
        cout << fu() << endl;

	}		
	return 0;
}

