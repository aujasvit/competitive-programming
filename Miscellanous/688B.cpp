#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int changes(vector <int> &a) {
	int ans = 0, carry = 0;
	for(int i = 1; i < a.size(); i++) {
		if(a[i] + carry == 0) continue;
		int dodo = carry;
		carry -= (a[i]+carry);
		ans += abs(a[i] + dodo);
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;
	cin >>t;
	while(t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		
		//cout << ans(a);
	}
	return 0;
}

