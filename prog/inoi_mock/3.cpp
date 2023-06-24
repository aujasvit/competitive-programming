#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()
int n, m, s;
int grid[1100][1100];
set <int> numbers;

bool check_s(int x, int y, int length, int breadth, int dd) {

	
	if(x + breadth - 1 > n) return false;
	if(y + length - 1 > m) return false;
	
	for(int i = x, j = 1; j <= breadth; i++, j++) {
		for(int k = y, dodo = 1; dodo <= length; k++, dodo++) {
			if(grid[i][k] - dd <= 0) return false;
		}
	}

	return true;
}
int dodo = 0;
void ans(int length, int breadth) {
	for(set <int, int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		int curr = *it;
		curr--;

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(check_s(i,j,length, breadth,curr)) dodo = max(dodo, curr);
			}
		}
	}
}



void fofo() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(i * j >= s) {
				ans(i, j);
			}
		}
	}
}


signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m >> s;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> grid[i][j];
			numbers.insert(grid[i][j]);
		}
	}

// 	cout << check_s(1,1, 2, 3, 0)  << endl;

	fofo();
	cout << dodo << endl;

	return 0;
}