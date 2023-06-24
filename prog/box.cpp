#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int update(vector <int> &a, int curr) {
	if(a[curr] == false) {
		return false;
	}
	for(int i = curr + 1; i < a.size(); i++) {
		if(!a[i]) {
			curr = i;
			return curr;
		}
	}
	return -1;
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector <int> q(n);
		int ff = 0;
		for(int i = 0; i < n; i++) {
			cin >> q[i];
			if(q[i] < i + 1) {
				ff = -1;
			}
			if(i > 0 and q[i] < q[i - 1]) {
				ff = -1;
			}
		}
		if(ff == -1) {
			cout << -1 << endl;
			continue;
		}
		    priority_queue<int, vector<int>,greater<int> > dodo;

		vector <int> ans(n + 1);
		ans[0] = a[0];
		vector <bool> a(n + 1, false);
		a[a[0]] = true;
		int curr;
		curr = update(a, 1);
		for(int i = 1; i < n; i++) {
			if(q[i] == q[i - 1]) {
				ans[i] = curr;
				a[curr] = true;
				curr = update(a, curr);
			} else {
				ans[i] = q[i];
				a[q[i]] = true;
				curr = update(a,curr);
			}
		}

		for(int i = 0; i < n; i++) cout << ans[i] << " ";

		cout << endl;


	}		
	return 0;
}

