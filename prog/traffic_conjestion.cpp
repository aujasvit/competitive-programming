#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

int LocateCentre(int n, int p[], int s[], int d[]) {
	

	vector <int> forward(n), backward(n);
	forward[0] = p[0];
	for(int i = 1; i < n; i++) {
		forward[i] = forward[i - 1] + p[i];
	}

	backward[n - 1] = p[n - 1];

	for(int i = n - 2; i >= 0; i--) {
		backward[i] = backward[i + 1] + p[i];
	}

	int mi = backward[0] - p[0];
	int curr = 0;
	for(int i = 1; i < n; i++) {
		int d = max(backward[i] - p[i], forward[i - 1]);
		if(d < mi) {
			mi = d;
			curr = i;
		}
	}

//	cout << mi << " " << curr << endl;

    return curr;
}


// signed main() {
// 	int n = 3;
// 	int p[] = {1,3,2};
// 	int d[] = {1,2};
// 	int s[] = {0,1};

// 	LocateCentre(n,p, s, d);
// }