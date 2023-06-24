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
		if(n % 2 == 0) {
			for(int i = n; i > 0; i--) {
				cout << i << " ";
			}
		} else {
			for(int i = n; i > 0; i--) {
				if(i == n/2 + 1) {
					cout << i - 1 <<" " << i << " ";
					i--;
				} else {
					cout << i << " ";
				}
			}
		}
	}		
	return 0;
}

