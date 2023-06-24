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


	// for(int i = 2; i <= n; )

	int ans() {
		int dp[n + 10][2];

		//0 --> non periodic
		//1 --> periodic

		dp[0][0] = dp[0][1] = 0;
		dp[1][0] = 2;dp[1][1] = 0;
		dp[2][0] = dp[2][1] = 2;
		//bool isprime[n + 10] = {0};//0 means isprime
		int fu = 1;
		

		vector <int> mult;
		fu = 4;
		for(int i = 3; i <= n; i++) {


			int f, d = (fu * 2) % m;
			fu *= 2;fu %= m;f = d;

			for(int j = 2; j * j <= n; j++) {
				if(i % j == 0) {
					d -= dp[j][0] % m;
					d += m;
					d %= m;
					if(j * j == n) continue;
					d -= dp[(int)(i/j)][0] % m;
					d += m;
					d %= m;
				}
			}
			d -= 2;d += m;d %= m;
			dp[i][0] = d % m;
			if(dp[i][0] < 0) dp[i][0] += m;
		}

		return dp[n][0] % m;

	}

	signed main() {
		ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
		cin >> n >> m;
		cout << ans() << endl;
		return 0;
	}

