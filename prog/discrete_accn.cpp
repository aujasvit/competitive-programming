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
	int t;cin >>t;
	while(t--) {
		int n, l;
		cin >> n >> l;
		vector <int> flags(n);
		for(int i = 0; i < n;i++) cin >> flags[i];
		int s1, s2;
		s1 = s2 = 1;
		int pos1 = 0, pos2 = l;

		int ans = 0;
		while(pos1 < pos2) {

				if(binary_search(flags.begin() , flags.end(), pos1)) {
					s1 += 1;
				}


				if(binary_search(flags.begin() , flags.end(), pos2)) {
					s2 += 1;
				}

				
			}

	}		
	return 0;
}

