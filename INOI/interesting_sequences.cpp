//Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI2002

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int n,f;
vector <int> a;
vector <pii> whatmatters;

bool predicate(int curr) {
	int dp[n + 2];
//	dp[0][0] = 0;
	for(int i = 0; i < n; i++) {
		dp[i] = 1;
		for(int j = 0; j < i; j++) {
			if(abs(a[i] - a[j]) >= curr) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
    for(int i = 0; i < n ; i++) {
        if(dp[i] >= f) return true;
    }
	if(dp[n - 1] >= f) return true;
	return false;
}

int binary_search() {
	int l = 0, r = n + 2;
	
	for(int i = 0; i < n; i++) {
	    for(int j = i + 1; j < n; j++) {
	        if(whatmatters[i].fr == whatmatters[j].fr) l = max(abs(whatmatters[i].sc - whatmatters[j].sc), l);
	    }
	}
	
	while(r - l > 1) {
		int m = (l + r)/2;
		if(predicate(m)) l = m;
		else r = m;
	}

	return l;
}

bool comp(pii a, pii b) {
    if(a.fr == b.fr) return a.sc > b.sc;
    
    return a.fr > b.fr;
}


signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> f;
		a.clear(); a.resize(n);
		whatmatters.clear();
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			whatmatters.pb(mp(a[i], i));
		}
		sort(whatmatters.begin(), whatmatters.end(), comp);
		for(int i = 0; i < n; i++) {
			a[i] = whatmatters[i].sc;
		}
        // cout << predicate(3) << endl;
		int k = binary_search();
		cout << k << endl;
	}
	
	return 0;
}
