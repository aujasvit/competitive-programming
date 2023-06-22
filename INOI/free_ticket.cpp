//Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI1402

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define pb push_back

int floyd(vector <vector <int> > a, map <pair <int, int> , int> weight, set <pair <int, int > > edges) {
    int m[a.size()][a.size()];
    
    
    for(int row = 1; row < a.size(); row++) {
        for(int col = 1; col < a.size(); col++) {
            if(row == col) m[row][col] = 0;
            else if(edges.find(mp(row, col)) != edges.end()) {
                m[row][col] = weight[mp(row, col)];
            } else {
                m[row][col] = INT_MAX;
            }
        }
    }
    
    
    for(int i = 1; i < a.size(); i++) {
        for(int j = 1; j < a.size(); j++) {
            for(int k = 1; k < a.size(); k++) {
                m[j][k] = min(m[j][k], m[j][i] + m[i][k]);
            }
        }
    }
    
    int ans = INT_MIN;
    for(int col = 1; col < a.size(); col++) {
        for(int row = 1; row < a.size(); row++) {
            ans = max(ans, m[row][col]);
        }
    }
    
    
    return ans;
}



signed main() {
    int c, f;
    
    cin >> c >> f;
    
    vector <vector <int> > a(c + 1);
    
    map <pair<int,int> , int> weight;
    
    set <pair <int, int> > edges;
    
    for(int i = 0; i < f; i++) {
        int k, l, m;
        cin >> k >> l >> m;
        weight[mp(k, l)] = m;
        weight[mp(l, k)] = m;
        
        edges.insert(mp(k, l));
        edges.insert(mp(l, k));
    }
    
    
    
    
    cout << floyd(a, weight, edges) << endl;
    
    
    
    return 0;
    
    
}