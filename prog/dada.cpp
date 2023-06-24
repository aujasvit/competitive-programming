#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

map<char, pii> freq;

string s;

int mi = INT_MAX,ma = INT_MIN;//col
char mim, mam;

void travel() {
	int r = 0, c = 0;
	for(int i = 0; i < s.size() ;i++) {
		pii curr = freq[s[i]];
		r += curr.fr; c += curr.sc;
		if(r <= mi and (s[i] == 'W' or s[i] == 'E')) {
			mi = r;
			mim = s[i];
		}

		if(r >= ma and (s[i] == 'W' or s[i] == 'E')) {
			ma = r;
			mam = s[i];
		} 
	}
    // cout << mim << " " << mam << endl; return;
	if(mim == 'W' and mam == 'E' ) {
		cout << "CW" << endl;
	} else {
		cout << "CCW" << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;cin >> t;
	freq['N'] = mp(1,0);
	freq['S'] = mp(-1,0);
	freq['E'] = mp(0,1);
	freq['W'] = mp(0, -1);
    
	while(t--) {
	    mi = INT_MAX;ma = INT_MIN;
		cin >> s;
		travel();
	}

	return 0;
}

