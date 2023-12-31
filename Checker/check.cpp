// Author : ysh
// 2023/08/03 Thu 13:44:16
#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;
#define dt(i,j,k,l) ((i - k) * 1LL * (i - k) + (j - l) * 1LL * (j - l))
long double alldt(vector<pair<int,int>>&f,int x,int y) {
    long double ans = 0;
    for(auto &i : f) {
        ans = ans + sqrtl(dt(i.first,i.second,x,y));
    }
    return ans;
}
int main(int ac,char* as[]) {
 //   ios::sync_with_stdio(false);
 //   cin.tie(0);

    registerTestlibCmd(ac,as);

    int n = inf.readInteger();
    vector<pair<int,int>>input(n);
    for(auto &i : input) {
        i.first = inf.readInteger();
        i.second = inf.readInteger();
    }

    int x,y;
    x = ans.readInt();
    y = ans.readInt();

    int xx,yy;
    xx = ouf.readInt(-int(1000000),int(1000000),"x");
    yy = ouf.readInt(-int(1000000),int(1000000),"y");

    #define f input
    // cerr<<alldt(f,x,y)<<" "<<alldt(f,xx,yy);
    long double aans = alldt(f,x,y);
    long double ptas = alldt(f,xx,yy);
    if(aans <= ptas && abs(aans - ptas) < 1) quitf(_ok,"%d 個點的最小總長度是 %Lf，比正確答案大了 %Lf",n,ptas,ptas - aans);
    else if (aans < ptas) quitf(_wa,"答案並非最小值，答案差了 %Lf",abs(ptas - aans));
    else quitf(_ok,"程式輸出了更小的合法答案 %Lf 恭喜",ptas);
}