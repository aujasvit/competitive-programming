#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, k;
	cin >> n >> k;

	int a[n + 1];
	for(int i = 1; i <= n; i++) cin >> a[i];

	int forward[n + 1], back[n + 1];

	//
	//forward till k = -1 -inf
	//forward at k = 0 = 0
	//forward at i>k = max(forward[i - 1] , forward[i - 2], forward[i - 3]) + a[i]

	for(int i = 1; i <= n; i++) {
		if(i < k) {
			forward[i] = INT_MIN;
		} else if(i == k) {
			forward[i] = 0;
 		} else {
			forward[i] = INT_MIN;
			if(i - 1 >= k) {
				forward[i] = max(forward[i],forward[i - 1]);
			}
			
			if(i - 2 >= k) {
				forward[i] = max(forward[i - 2], forward[i]);
			}


			forward[i] += a[i];
		}
	}


	//back

	back[1] = 0;
	for(int i = 2;i <= n; i++) {
		back[i] = INT_MIN;
		if(i - 1 >= 1) { 
				back[i] = max(back[i],back[i - 1] + a[i - 1]);
			}
			
			if(i - 2 >= 1) {
				back[i] = max(back[i], back[i - 2] + a[i - 2]);
			}


	}

	int fin = INT_MIN;

	for(int i = k; i <= n; i++) {
		fin = max(fin, forward[i] + back[i]);
	}

	cout << fin << endl;

	return 0;
}

