//Problem Link: https://www.codechef.com/INOIPRAC/problems/TINOI17B

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

int n, s;
vector <int> a;
vector <int> strength;

int sum(int number) {
	int fin = 0;
	
	while(number > 0) {
		fin += number % 10;
		number /= 10;
	}

	return fin * fin * fin;
}

int dp[5010][5010];

int ans(int curr = 0, int no = 0) {

	if(curr == n) return 0;
	if(dp[curr][no] != -1) return dp[curr][no];

	int k, l;
	k = ans(curr + 1, no + 1);
	l = ans(curr + 1, no) + (strength[no] * a[curr]);

	dp[curr][no] = max(k, l);
	return max(k, l);

}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>> n >> s;
	a.resize(n);
	strength.resize(n + 10);
	for(int i = 0; i < n; i++) cin >> a[i];

	for(int i = 0; i < 5010; i++) {
		for(int j = 0; j < 5010; j++) {
			dp[i][j] = -1;
		}
	}


	strength[0] = s;
	for(int i = 1; i <= n; i++) strength[i] = strength[i - 1] + sum(strength[i - 1]);

	cout << ans() << endl;
	return 0;
}