//Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI1501

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

vector <int> a, b;//1 indexed
int n;

int front() {

	if(n <= 2) return INT_MIN;

	int dp[2][n + 2];
	dp[0][0] = dp[1][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;
	dp[1][3] = a[1] + a[3] + b[2];
	int k = INT_MIN;
	for(int i = 4; i <= n; i++) {
		dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
		dp[1][i] = max(dp[1][i - 1] - a[i - 1] + b[i - 1] + a[i], a[i - 2] + a[i] + b[i - 1]);

	}

	return max(dp[0][n],dp[1][n]);

}

int back() {
	int forward[n + 10] = {0};

	int dp[n + 10] = {0};
	for(int i = 1; i <= n; i++) {
		dp[i] = b[i];
		if(i > 1) dp[i] += dp[i - 1];
	}
	forward[1] = a[1];
	for(int i = 2; i <= n; i++) {
		forward[i] = max(dp[i - 1] + a[i], forward[i - 1]);
	}

	int dodo[n + 10] = {0};

	dodo[n] = a[n];
	for(int i = n - 1; i >= 1; i--) {
		dodo[i] = max(dodo[i + 1], a[i] + dp[n] - dp[i]);
	}
	int fin = INT_MIN;
	for(int i = 2; i <= n; i++) {
		fin = max(fin, dodo[i] + forward[i - 1]);
	}

	return fin;
}

int adj() {

	int l = INT_MIN;
	for(int i = 2; i <= n; i++) {
		l = max(l, a[i] + a[i - 1]);
	}

	return max(l, a[1] + a[n]);

}

int indiv() {
	int l = INT_MIN;

	for(int i = 1; i <= n; i++) {
		l = max(l, a[i]);
	}

	return l;
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	a.resize(n + 1);b.resize(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];



	vector <int> d;
	d.pb(front());d.pb(indiv());d.pb(adj());d.pb(back());
	sort(d.begin(), d.end());

	for(int i = 3; i >=0; i--) {
		if(d[i] == 0) continue;
		cout << d[i] << endl;
		return 0;
	}
	//cout << front() << " " << back() << endl;

	cout << 0 << endl;

	return 0;
}