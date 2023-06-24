#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 5000, "n");
    inf.readEoln();
    for (int i=0; i<n-1; ++i) {
        int a = inf.readInt(1,1000000000,"a");
        inf.readSpace();
    }
    int a = inf.readInt(1,1000000000,"a");
    inf.readEof();
}