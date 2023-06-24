#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

vector <int> dodo;

int bst(int d) {
	int i = 0, j = dodo.size();
	while(j - i > 1) {
		int m = (i + j)/2;
		if(dodo[m] > d) {
			j = m;
		}  else {
			i = m;
		}
	}

	return dodo[j];
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;
	cin >> t;
	map <int, int> d;
	int count = 1;
	for(int i = 0; i < 10000000; i+=0) {
		i += count;
		count++;
		dodo.pb(i);
		d[i] = count - 1;
	}
	while(t--) {
		int x;
		cin >> x;
		if(x == 2) {
			cout << 3 << endl;
			continue;
		}
		if(d[x] != 0) {
			cout << d[x] << endl;
			continue;
		}
		//if(x == 1) {cout << 1 << endl;continue;}

		int ans = 0;
		ans += x - 1;
		int fofo = bst(x);
		int fu = d[fofo];
		if(x == fofo - 1) {
			cout << fu + 1 << endl;
			continue;
		} else {
			cout << fu << endl;
		}
	}
	return 0;
}

