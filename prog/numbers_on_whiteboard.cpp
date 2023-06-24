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
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if(n % 2 == 1) {
			int ans = 2;
			cout << ans << endl;
			cout << n << " " << n - 1 << endl;
			int curr = n;
			for(int i = n - 2; i >= 1; i--) {
			    cout << i << " " << curr << endl;
			    curr = (i + curr)/2;
			}
		
		} else {
			int ans = 2;
			cout << ans << endl;
			cout << n << " " << n - 1 << endl;
			int curr = n;
			for(int i = n - 2; i >= 1; i--) {
			    cout << i << " " << curr << endl;
			    curr = (i + curr)/2;
			}
			
	}		
	}
	return 0;
}

