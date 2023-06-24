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
int a[50010];


int ans() {
	for(int i = 2; i <= n; i++) a[i] += a[i - 1];
	int fin = 0;
	int rem[10] = {0};//0-->6
	for(int i = 1; i <= n; i++) {
		int curr = a[i]%7;
		if(curr == 0) fin = max(fin,(int)1);
		if(rem[curr] == 0) {
			rem[curr] = i;
		} else {
			fin = max(fin, i - rem[curr]);
		}
	}

	return fin;
}



signed main() {
	freopen("div7.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("div7.out", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	for(int i = 1;i <= n; i++) cin >> a[i];

	cout << ans() << endl;
	return 0;
}

