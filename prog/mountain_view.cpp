#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int n;
vector <pii> segment;

int ans() {
	int fin =n;

	int end = INT_MIN;
	sort(all(segment));
	for(int i = 0; i < n; i++) {
		if(end >= segment[i].sc) {
			fin--;
		}
		end = max(end, segment[i].sc);
	}

	return fin;
}

signed main() {
		freopen("mountains.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("mountains.out", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) {
		int k, l;
		cin >> k >> l;
		int alpha = k - l, beta = k + l;
		segment.pb(mp(alpha, beta));
	}
	cout << ans() << endl;
	return 0;
}

