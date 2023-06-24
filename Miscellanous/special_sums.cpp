#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()
vector <int> a,b;

int ans = INT_MIN;
vector <int> fwd;

int fc() {
	vector <vector <int> > dp(2);
	for(int i = 0; i < 2; i++)dp[i].resize(n + 10);

	dp[0][0] = INT_MIN;
	dp[1][0] = a[i];
	bool d = true;

	for(int i = 1; i < a.size(); i++) {
		dp[0][i] = max(dp[0][0], dp[1][0]);
		if(true) {
			dp[1][i] = max()
		}
	}

}

void fillbwd() {
	bwd.resize(a.size());

}



signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin >> n;

	a.resize(n);b.resize(n);
	for(int i = 0; i < n; i++){cin >> a[i];ans = max(ans, a[i]);}
	for(int i = 0; i < n; i++){cin >> b[i];if(i != 0)b[i] += b[i-1];}

	vector <int> fwd, bwd;
	return 0;
}
