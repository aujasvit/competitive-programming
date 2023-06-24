#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int x,y , k , m;
int dodo;

int dp[105][105][105];
void ans(int currx, int curry, int left){
	if(left == 0) {
		dodo = min(dodo, abs(currx + curry - m));
		return;
	}

	if(dp[currx][curry][left]) return;
	dodo = min(dodo, abs(currx + curry - m));

	ans(currx, 0, left - 1);
	ans(0, curry, left - 1);

	ans(x, curry, left - 1);
	ans(currx, y, left - 1);

	ans(min(x, currx+ curry), currx + curry - min(x, currx+ curry), left - 1);
	ans(currx + curry - min(y, currx + curry), min(y, currx + curry), left - 1);

	dp[currx][curry][left] = 1;

}

signed main() {
	freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> x >> y >> k >> m;
    
    dodo = m;

	ans(0,0,k);

	for(int i = 0; i < 105; i++) {
		for(int j = 0; j < 105; j++) {
			for(int l = 0; l < 105; l++) {
				dp[i][j][l] = 0;
			}
		}
	}

	cout << dodo << endl;

	return 0;
}

