// Author : ysh
// 2023/07/27 Thu 16:37:44
#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;
int main(int ac,char* as[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    registerGen(ac,as,1);

    long long a = atoll(as[1]);
    long long b = atoll(as[2]);
    long long m = atoll(as[3]);

    b = rnd.next(-b,b);

    cout<<(rnd.next(0,1) == 1 ? 1LL : -1LL)<<" "<<b<<"\n"<<m<<"\n";
    while(m--) {
        cout<<rnd.next(0LL,a)<<"\n";
    }
    return 0;
}