#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int w[300], t[300];
int n, W;
//talent/weight
int total = 0;
float currwt = 0, currht = 0;

float dp[310][62500001];

float finansihope() {
    float ans = 0;
    dp[1][0] = 0;
	for(int i = 1; i <= total; i++) {
		if(i == t[1]) dp[1][i] = w[1];
		else dp[1][i] = INT_MAX;
	}
	for(int i = 2; i <= n; i++) {
		for(int f = 0; f <= total; f++) {
			if(f == 0) dp[i][f] = 0;
			if(f < t[i]) {
				dp[i][f] = dp[i - 1][f];
			}
			dp[i][f] = min(dp[i - 1][f], dp[i - 1][f - t[i]] + w[i]);
			if(dp[i][f] >= W) {
			    ans = max(ans, f/dp[i][f]); 
			   // if( (int)(1000*(f/dp[i][f])) == 1733) cout << dp[i][f] << " " << f << endl; 
			   }
		}
	}
    	
//	cout << dp[1][21] << endl;
	

return ans;
}


// float ans2() {
// 	pair <float, float>  dp[310][2];
// //wt, talent
// 	dp[1][0] = mp(0,0);
// 	dp[1][1] = mp(w[1], h[1]);
// 	for(int i = 2; i <= n; i++) {
// 		float p1 = dp[i - 1][0].sc/dp[i - 1][0].fr;
// 		float p2 = dp[i - 1][1].sc/dp[i - 1][1].fr;

// 		if(p1 > p2) {
// 			dp[i][0].fr = dp[i - 1][0].fr;
// 			dp[i][0].sc = dp[i - 1][0].sc;
// 		} else {
// 			dp[i][0].fr = dp[i - 1][1].fr;
// 			dp[i][0].sc = dp[i - 1][1].sc;
// 		}

// 		float p3 = (dp[i - 1][0].sc + h[i])/(dp[i - 1][0].fr + w[i]);
// 		float p4 = (dp[i - 1][1].sc + h[i])/(dp[i - 1][1].fr + w[i]);

// 		if(p3 > p4) {
// 			dp[i][1].fr = dp[i - 1][0].fr + w[i];
// 			dp[i][1].sc = dp[i - 1][0].sc + h[i];
// 		} else {
// 			dp[i][1].fr = dp[i - 1][1].fr + w[i];
// 			dp[i][1].sc = dp[i - 1][1].sc + h[i];
// 		}
// 	}

// 	float a1 = dp[n][0].sc/dp[n][0].fr;
// 	float a2 = dp[n][1].sc/dp[n][1].fr;

// 	return max(a1, a2);
// }



// float ans(int curr) {
// 	if(curr > n) {
// 		if(currwt >= W) {
// 			return currht/currwt;
// 		} else {
// 			return INT_MIN;
// 		}
// 	}
// 	int k1 = currwt, k2 = currht;
// 	float a1 = ans(curr + 1);
// 	currwt = k1 ; currht = k2;
// 	currwt += w[curr]; currht += t[curr];

// 	float a2 = ans(curr + 1);

// 	return max(a1, a2);
// }

// float ans(int curr, float currwt, float currht) {
// 	if(curr > n) {
// 		if(currwt >= W) {
// 			return currht/currwt;
// 		} else {
// 			return INT_MIN;
// 		}
// 	}

// 	float a1 = ans(curr + 1, currwt, currht);
// 	float a2 = ans(curr + 1, currwt + w[curr], currht + t[curr]);
// 	return max(a1, a2);
// }


signed main() {
	freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> W;
	for(int i = 1; i <= n; i++) {cin >> w[i] >> t[i]; total += t[i];}

	float d = finansihope();
	
//	cout << total << endl;

	cout << (int)(1000*d) << endl;

	return 0;
}

