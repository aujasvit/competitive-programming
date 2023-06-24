#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()
int r,c;
string grid[2010];
int dd[2010][2010];
pii fire, bear;
/*
	1 1 1 2 2
	1 1 1 1 1
*/

bool visited[2010][2010];

int path(int x = bear.fr, int y = bear.sc + 1) {
    if(dd[x][y] == 0) return INT_MAX;
    if(x == r or y == c or x == 1 or y == 1) return 2 * (1 + abs(x - bear.fr) + abs(y - bear.sc - 1));
    if(visited[x][y]) return INT_MAX;
    visited[x][y] = 1;
    
    // cout << x << " " << y << endl;
    
    int l1 , l2, l3, l4;
    l1 = l2 = l3 = l4 = INT_MAX;

    
    	l1 = path(x - 1, y);
    

    l2 = path(x + 1, y) ;

    
    	l3 = path(x, y - 1);
    

    l4 = path(x, y + 1);
    
    
    
    return min({l1,l2,l3,l4});
    
    
}
void correct() {

	for(int i = 1; i <= r; i++) {
		for(int j = 0; j < c; j++) {
			if(grid[i][j] == '@') {
				dd[i][j + 1] == 0;
			} else {
				int t1 = (abs(fire.fr - i) + abs(fire.sc - j));
				int t2 = abs(i - bear.fr) + abs(j - bear.sc);
				t2 *= 2;
				t2++;
				if(t2 >= t1) {
					dd[i][j + 1] = 0;
				} else {
					dd[i][j + 1] = 1;
				}
			} 
		}
	}

// 	for(int i = 1; i <= r; i++) {
// 		for(int j = 1; j <= c; j++) {
// 			cout << dd[i][j];
// 		}
// 		cout << endl;
// 	}
}


signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> r >> c;
	
	for(int i = 1; i <= r; i++) {
		cin >> grid[i];
		for(int j = 0; j < c; j++) {
			if(grid[i][j] == 'F') fire = mp(i, j);
			else if(grid[i][j] == 'B') bear = mp(i, j);
			visited[i][j + 1] = 0;
		}
	}
	correct();

	int d = path();
	
	if(d >= INT_MAX) cout << -1 << endl;
	else cout << d << endl;
	
	
	


	return 0;
}