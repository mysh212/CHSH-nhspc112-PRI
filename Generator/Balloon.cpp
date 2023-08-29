// Author : ysh
// 2023/08/24 Thu 17:21:47
#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;
int main(int ac,char* as[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    registerGen(ac,as,1);
    int n = atoi(as[1]);
    int r = atoi(as[2]);
    bool o = atoi(as[3]);
    bool t = atoi(as[4]);

    if(t) {
        n = rnd.next(1,n);
    }

    cout<<n<<"\n";
    while(n--) {
        cout<<rnd.next((o ? -r : 0),r)<<" \n"[n == 0];
    }
    return 0;
}