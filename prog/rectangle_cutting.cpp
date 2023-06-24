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
	int l, b;
	cin >> l >> b;
	int dp[l + 10][b + 10];

	for(int row = 1, col = 1; col <= b; col++) {
		dp[row][col] = col - 1;
	} 

	for(int  row = 1, col = 1; row <= l; row++) {
		dp[row][col] = row - 1;
	}

	for(int row = 2; row <= l; row++) {
		for(int col = 2; col <= b; col++) {
			if(row==col) {
				dp[row][col] = 0;
				continue;
			}

			int temp = INT_MAX;
			//keeping row same
			for(int i = 1; i < col; i++) {
				temp = min(temp, (int)1 + dp[row][i] + dp[row][col - i]);
			}

			for(int i = 1; i < row; i++) {
				temp = min(temp, (int)1 + dp[i][col] + dp[row - i][col]);
			}
			dp[row][col] = temp;//f u
		}
	}

	cout << dp[l][b] << endl;
	return 0;
}

