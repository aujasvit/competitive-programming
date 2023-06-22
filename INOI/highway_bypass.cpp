//Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI1401

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair

int r, c, dodo;

vector <int> a[310];
int dp[310][310][310][2];
int mod = 20011;

int ans(int row, int col, int d = 0, bool can = true) {
	if(row > r || col > c) return 0;
	if(d > dodo) return 0;
	if(a[row][col] == 0) return 0;
	if(row == r && col == c) {return 1;}

	if(dp[row][col][d][can] !=-1) return dp[row][col][d][can];


	if(can) {
		int k = ans(row + 1, col, d + 1, can);
		int l = ans(row, col + 1, 1, !can);
		
		dp[row][col][d][can] = ((k % mod) + (l % mod)) % mod;
		//cout << row << " " << col << " " << ((k % mod) + (l % mod)) % mod << endl;
		return ((k % mod) + (l % mod)) % mod;
	} else {
		int k = ans(row, col + 1, d + 1, can);
		int l = ans(row + 1, col, 1, !can);
		
		dp[row][col][d][can] = ((k % mod) + (l % mod)) % mod;
		//cout << row << " " << col << " " << ((k % mod) + (l % mod)) % mod << endl;
		return ((k % mod) + (l % mod)) % mod;
	}
}


signed main() {
	cin >> r >> c >> dodo;
	

	for(int i = 1; i <= r; i++) {
		a[i].pb(0);
		int temp;
		for(int col = 1; col <= c; col++) {
			cin >> temp;
			a[i].pb(temp);
		}
	}


	for(int i = 1; i <= r; i++) {
			for(int j = 1; j <= c; j++) {
				for(int k = 0; k <= dodo + 1; k++) {
					for(int l = 0; l <= 1; l++) {
						dp[i][j][k][l] = -1;
					}
				}
			}
		}
	int k = ans(1, 1);

	cout << k << endl;



	// if(k == -1) cout << 0 << endl;
	// else cout << k << endl;

	return 0;

}
