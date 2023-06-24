#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()
int r,c,m;
string s;
string grid[102];


void count2() {
	int dp[s.size() + 10][r + 10][c + 10];
	//dp[i][j][k]
	// whether is this position possible with the remaining string[i till end] 
	//check whether dp[]
	//
	//
	//
	//

	for(int i = 0; i <= s.size() + 5; i++) {
		for(int j = 0; j <= r + 5; j++) {
			for(int k = 0; k <= c + 5; k++) {
				dp[i][j][k] = false;
			}
		}
	}

	for(int i = 1; i <= r; i++) {
	for(int j = 0; j < c; j++) {
		if(grid[i][j] == '#') {
			dp[0][i][j] = false;
			continue;
		}
	if(s[0] == 'N') {
		if(i != r and grid[i + 1][j] != '#') {
			dp[0][i][j] = 1;
		}
	} else if(s[0] == 'S') {
		if(i != 1 and grid[i - 1][j] != '#') {
			dp[0][i][j] = 1;
		}
	} else if(s[0] == 'W') {
		if(j != c - 1 and grid[i][j + 1] != '#') {
			dp[0][i][j] = 1;
		}

	} else if(s[0] == 'E') {
		if(j != 0 and grid[i][j - 1] != '#') {
			dp[0][i][j] = 1;
		}
	} else {
		
		if(j != 0 and grid[i][j - 1] != '#') {
			dp[0][i][j] = 1;
		}
		if(j != c - 1 and grid[i][j + 1] != '#') {
			dp[0][i][j] = 1;
		}
		if(i != 1 and grid[i - 1][j] != '#') {
			dp[0][i][j] = 1;
		}
		if(i != r and grid[i + 1][j] != '#') {
			dp[0][i][j] = 1;
		}

	}		
	}
}

	for(int i  = 1; i < s.size(); i++) {
		for(int row = 1; row <= r; row++) {
			for(int col = 0; col < c; col++) {
				//can you reach row col using first i - 1 commands
if(dp[i - 1][row][col]) {
	if(s[i] == 'N') {
		if(row != 1 and grid[row - 1][col] != '#') {
			dp[i][row - 1][col] = 1;
		} 
	} else if(s[i] == 'S') {
		if(row != r and grid[row + 1][col] != '#') {
			dp[i][row + 1][col] = 1;
		} 
	} else if(s[i] == 'W') {
		if(col != 0 and grid[row][col - 1] != '#') {
			dp[i][row][col - 1] = 1;
		} 
	} else if(s[i] == 'E') {
		if(col != c - 1 and grid[row][ col + 1] != '#') {
			dp[i][row][col] = 1;
		}

	} else {
		if(row != 1 and grid[row - 1][col] != '#') {
			dp[i][row - 1][col] = 1;
		} 
		if(row != r and grid[row + 1][col] != '#') {
			dp[i][row + 1][col] = 1;
		}
		if(col != 0 and grid[row][col - 1] != '#') {
			dp[i][row][col - 1] = 1;
		}
		if(col != c - 1 and grid[row][ col + 1] != '#') {
			dp[i][row][col] = 1;
		}

	}
}
			}
		}
	}


	for(int i = 1; i <= r; i++) {
		for(int j = 0; j < c; j++) {
			cout << dp[s.size() - 1][i][j] << " ";
		}
		cout << endl;
	}

}



signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> r >> c >> m;
	for(int i = 1; i <= r; i++) {
		cin >> grid[i] ;
	}
	cin >> s;

	count2();
	return 0;
}

