#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define fr first
#define sc second
#define all(a) a.begin(),a.end()

vector <string> lmao;

string extract(int curr, int index) {
	string fu = lmao[curr];
	string fin = "";
	for(int i = index; i < fu.size() and fu[i] != ' '; i++) {
		char k = lmao[curr][i];
		fin += k;
	}
	return fin;
}
string fff(int curr) {
	string fin = "", fu = lmao[curr];
	for(int i = fu.size() - 1; i >= 0 and fu[i] != ' '; i--) {
		fin += lmao[curr][i];
	}
	return fin;
}


signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin >> n;
	int ff = 2;

	// for(int i = 1; i <= n; i++) {
	// 	string s;
	// 	cin >> s;
	// 	lmao.pb(s);
	// }
	map <string, int> mm;
	map <string, int> dp;
	mm["Tiger"] = 1;mm["Rabbit"] = 2;mm["Dragon"] = 3;mm["Snake"] = 4;mm["Horse"] = 5;mm["Goat"] = 6;mm["Monkey"] = 7;mm["Rooster"] = 8;mm["Dog"] = 9;mm["Pig"] = 10;mm["Rat"] = 11;mm["Ox"] = 12;
	//Ox, Tiger, Rabbit, Dragon, Snake, Horse, Goat, Monkey, Rooster, Dog, Pig, Rat
	dp["Bessie"] = 0;
	map <string,string> fff;
	for(int i = 0; i < n; i++) {

		string who, whome, k, al,be,he,she,dd, d;
		cin >> who >> al >> be >> k >> d >> he >> she >> whome;
		fff[who] = d;
		// who = extract(i, 0);
		// int ffs = 9 + who.size();
		// k = extract(i, ffs);
		// int l;
		// whome = fff(i);
		   int l;
	//	cout << who << " " << k << " " << whome << endl;
	
		if(k == "previous") {
			string cc = fff[whome];
			int m = mm[cc] - mm[d];
			if(m < 0) l = -1*(12 + m);
			else if(m == 0) l = -12;
			else l = -1*m;
		} else {
			string cc = fff[whome];
			int m = mm[d] - mm[cc];
			if( m < 0) l = 12 + m;
			else if(m == 0) l = 12;
			else l = m;
		}
		//int curr;
		dp[who] = dp[whome] + l;
	}

	int find = dp["Elsie"];

	cout << abs(find) << endl;

	return 0;
}

