// Author : ysh
// 2023/08/03 Thu 13:36:30
#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;
int main(int ac,char* as[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    registerGen(ac,as,1);
    int n = atoi(as[1]);
    int a = atoi(as[2]);
    int b = atoi(as[3]);

    n = rnd.next(1,n);
    cout<<n<<"\n";
    while(n--) {
        cout<<rnd.next(-a,a)<<" "<<rnd.next(-b,b)<<"\n";
    }
    return 0;
}