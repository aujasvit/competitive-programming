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
	int t;cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int alpha = 1, beta = n;
		for(int i = 1; i <k; i++) {
			alpha++;
			beta--;
			if(beta < 1) beta = n;
			if(alpha > n) alpha = 1;
			if(alpha == beta) alpha++;
			if(alpha > n) alpha = 1;
			cout << alpha << endl;
		}
	}
	return 0;
}

