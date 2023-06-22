//Problem Link:https://cses.fi/problemset/task/1158

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define all(a) a.begin(), a.end()

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, W;
	cin >> n >> W;
	vector <int> v(n + 1), w(n + 1);

	for(int i = 1; i <= n; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) cin >> v[i];
		/*
	int dp[W + 10][n + 10];
	
	for(int row = 0; row < W + 10; row++) {
		dp[row][0] = 0;
	}

	for(int row = 0; row < n + 10; row++) {
		dp[0][row] = 0;
	}

	//row = wt, col = n

	for(int row = 1; row <= W; row++) {
		for(int col = 1; col <= n; col++) {
			if(row - w[col] >= 0) {
				dp[row][col] = max(dp[row - w[col]][col - 1] + v[col], dp[row][col - 1]);
			} else {
				dp[row][col] = dp[row][col - 1];
			}
		}
	}
	

	cout << dp[W][n] << endl;
	*/

	vector <int> dpold(W + 10, 0), dpnew(W + 10);
	dpnew[0] = 0;

// 	for(int row = 1; row <= W; row++) {
// 		for(int col = 1; col <= n; col++) {
// 			if(row - w[col] >= 0) {
// 				dpnew[row] = max(dpold[row - w[col]] + v[col], dpold[row]);
// 			} else {
// 				dpnew[row] = dpold[row];
// 			}
// 		}
// 		dpold = dpnew;
// 		dpnew[0] = 0;
// 	}

    for(int row = 1; row <= n; row++) {//present element fixed
        for(int col = 1; col <= W; col++) {
            if(col - w[row] >= 0) {
                dpnew[col] = max(dpold[col - w[row]] + v[row], dpold[col]);
            } else {
                dpnew[col] = dpold[col];
            }
        }
        dpold = dpnew;
        dpnew[0] = 0;
    }

	cout << dpnew[W] << endl;



	return 0;
}