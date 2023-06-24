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
	int n, m;
	cin >> n >> m;
	vector <int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
    int dodo = 1000000009;
	vector <pii > forward(n + 1, mp(0,0)), backward(n + 1, mp(0,0)), fin(n + 1, mp(0,0));

	int cmin = 1, cmax = m;

	for(int i = 0; i < n; i++) {
		if(a[i] == 0) {
			forward[i] = mp(cmin, cmax);
			cmin = max((int)1, cmin - 1);
			cmax = min(m, cmax + 1);
		}  else {
			cmin = max((int)1, a[i] - 1);
			cmax = min(m, a[i] + 1);
		}
	}

	cmin = 1;cmax =m;
	for(int i = n - 1; i >= 0; i--) {
		if(a[i] == 0) {
			backward[i] = mp(cmin, cmax);
			cmin = max((int)1, cmin - 1) % dodo;
			cmax = min(m, cmax + 1) % dodo;
		}  else {
			cmin = max((int)1, a[i] - 1) % dodo;
			cmax = min(m, a[i] + 1) % dodo;
		}
	}
int ans = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == 0) {
			int l = max(backward[i].first, forward[i].first) % dodo;
			int r = min(backward[i].second, forward[i].second) % dodo;
			fin[i].fr = l;
			fin[i].sc = r;
		}
	}
	int fofo = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == 0) {
			if(i > 0 and a[i - 1] == 0) {
				fofo= 3 * (fin[i - 1].sc - fin[i - 1].fr + 1);

				if(fin[i - 1].sc == m)ans--;
				if(fin[i - 1].fr == 1)ans--;

				ans %= dodo;
			} else {
				ans += fin[i].sc - fin[i].fr + 1;
				ans %= dodo;
			}

			if(a[i] == 1 and dodo != 0) {
				ans += fofo;
				ans %= dodo;
				fofo = 0;
			}
		}
	}

cout << ans << endl;
	return 0;
}

