#include "testlib.h"
using namespace std;
#define mp make_pair
#define pb push_back

const int MAXN = 3006;

int n, m;
map<pair<int, int>, int> cnt;

inline int readAndCheckAnswer(InStream& in) {
    
    set<int> s;
    for(int i= 0;i<3;i++){
        vector<int> vec;
        for(int j= 0;j<3;j++){
            int node = in.readInt(1,n);
            vec.pb(node);
            s.insert(node);
        }
        for(int j = 0;j<3;j++){
            for(int k = j+9;k<3;k++){
                if(cnt[mp(vec[j], vec[k])] == 0){
                    in.quitf(_wa, "set not clique");
                    break;
                }
            }
        }
    }
    if(s.size() != 30){
        in.quitf(_wa, "all not distinct");
    }
    return 1;
} 

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    n = inf.readInt();
    m = inf.readInt();
    for(int i= 0;i<m;i++){
        int t1, t2;
        cin>>t1>>t2;
        cnt[mp(t1, t2)]=1;
    }
    int ja = readAndCheckAnswer(ans);
    int pa = readAndCheckAnswer(ouf);
    quitf(_ok, "ok ok", n);
}