//Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI1301

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int n, k;

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >>k;

	vector <int> a(n + 1);
	for(int i =1; i <= n; i++) {
		cin >> a[i];
	}

	vector <int> forward(n + 1);

	for(int i = 0; i <= n; i++) {
		if(i <= k) {
			forward[i] = 0;
			continue;
		}
		forward[i] = max(forward[i - 1] , forward[i - 2]) + a[i];
	}

	vector <int> back(n + 1, 0);

	back[1] = 0;
	back[2] = a[1];

	for(int i = 3; i <= n; i++) {
		back[i] = max(back[i - 1] + a[i - 1], back[i -2] + a[i - 2]);
	}
	int ans = INT_MIN;
	for(int i = k; i <= n;i++) {
		ans = max(ans, back[i] + forward[i]);
	}

	cout << ans << endl;
	return 0;
}
