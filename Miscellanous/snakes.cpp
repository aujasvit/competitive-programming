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
int a[410];
int dpold[410][410], dpnew[410][410];

void newans() {

	
	for(int l = 0; l <= k; l++) {
		for(int curr = 1; curr <= n; curr++) {
			dpold[l][curr] = 0;
		}
	}

	for(int i = n; i >= 1; i--) {
		for(int l = 0; l <= k; l++) {
			for(int curr = 1; curr <= n;curr++) {

				if(l == 0) {
					if(a[curr] < a[i]) {
						dpnew[l][curr] = INT_MAX;
					} else {
						dpnew[l][curr] = dpold[l][curr] + a[curr] - a[i];
					}
				} else {
					dpnew[l][curr] = INT_MAX;
					if(a[curr] >= a[i]) {
						dpnew[l][curr] = dpold[l][curr] + a[curr] - a[i];
					}

					for(int dodo = 1; dodo <= n; dodo++) {
						if(a[dodo] == a[curr]) continue;
						if(a[dodo] < a[i]) continue;
						dpnew[l][curr] = min(dpnew[l][curr], dpold[l - 1][dodo] + a[dodo] - a[i]);
					}

				}

			}
		}
		
		for(int fu = 0; fu <= k; fu++) {
			for(int ff = 1; ff <= n; ff++) {
				dpold[fu][ff] = dpnew[fu][ff];
			}
		}

	}
	int fin = INT_MAX;
	for(int i = 1; i <= n; i++) {
		fin = min(fin, dpold[k][i]);
	}

	cout << fin << endl;

}



signed main() {
	freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];

// 	for(int i = 1; i <= n; i++) {
// 		for(int j = 1; j <= n; j++) {
// 			for(int k = 1; k <= n; k++) {
// 				dpnew[j][k] = -1;
// 			}
// 		}
// 	}
	newans();
	return 0;
}

