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
int v[1000], a[1000];

stack <int> curr;
int fin = INT_MIN;
void ans(int curr, int fu = 0;) {
	if(curr > n) {
		fin = max(fin, fu);
		return;
	}

	
	int k2 = INT_MIN;, k1 = ans(curr + 1, fu);
	if(a[curr] <= k) {
		if(a[curr] == curr.top() + k) {
			curr.pop();
			k2 = max(k2, ans(curr + 1, fu + v[curr]));
		}
	} else {
		curr.push(a[curr]);
		k2 = max(k2, ans(curr + 1, fu + v[curr]));
	}


}

int ans2(int i, int j) {
	if(j > i) return INT_MIN;

	if(j - i == 1) {
		if(a[j] == a[i] + k) return max(0, v[i] + v[j]);
		else return 0;
	} 

	int k1 = ans2(i + 1, j), k2 = ans2(i, j - 1);
	int k3 = INT_MIN;
	if(a[j] == a[i] + k) k3 = ans2(i + 1, j - 1) + v[i] + v[j];

	return max({k1,k2,k3});
}


signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> v[i];

	for(int i = 1; i <= n; i++) cin >> a[i];

	cout << ans2(1, n) << endl;
	return 0;
}

