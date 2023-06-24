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
	stack<int> dodo;
	vector <int> hist;
	int ans[hist.size() + 1] = {0};
	for(int i = 1; i <= hist.size(); i++) {
		
		if(dodo.empty()) {
			ans[i] = 1;
			dodo.push(i);
			continue;
		}
		while(dodo.top() >= hist[i]) {
			dodo.pop();
		}
		if(dodo.empty()) {
			ans[i] = 1;
		} else {
			ans[i] = dodo.top() + 1;
		}
		dodo.push(i);
	}

	for(int i = 1; i <= n; i++) cout << ans[i] << " " << endl;
	return 0;
}

