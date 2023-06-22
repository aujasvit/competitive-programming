//Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=694

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()
/*
0 --> hoof
1-->paper
2-->scissors
*/


int a[100009];
int dp[100009][25][3];
int n;

bool win(int curr, int opp) {
	if(curr == 0 and opp == 2) {
		return true;
	} else if(curr == 1 and opp == 0) {
		return true;
	} else if(curr == 2 and opp == 1) {
		return true;
	}

	return false;
}

int ans(int curr, int k, int i = 1) {
    
	if(dp[i][k][curr] != -1) {
		return dp[i][k][curr];
	}
	
	if(i > n) return 0;
	if(k < 0) return -1;
	
	int dd = 0, b = 1;//other two

	if(curr == 0) {
		dd= 1, b = 2;
	} else if(curr == 1) {
		dd = 0, b = 2;
	} else {
		dd = 0, b = 1;
	}
	
	int d = 0;
	d = max(ans(curr, k, i + 1), max(ans(dd, k - 1, i + 1), ans(b, k - 1, i+1) ) );
    
	if(win(curr, a[i]) )d++;
	
	dp[i][k][curr] = d;
	return d;

}

signed main() {
	freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int k;
	
	map <string, int> dodo;
	dodo["H"] = 0;
	dodo["P"] = 1;
	dodo["S"] = 2;

	cin >> n >> k;
	string f;
	for(int i = 1; i <= n; i++) {
		cin >> f;
		a[i] = dodo[f];
		for(int j = 0; j <= k; j++) {
			dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
		}
	}
    //cout << ans(0, k) << " " << ans(1,k) << " " << ans(2, k) << endl;
	int fu = max(ans(0, k), max(ans(1, k), ans(2, k)) );

	cout << fu << endl;

	return 0;
}

