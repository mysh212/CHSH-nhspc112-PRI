// Author : ysh
// 03/23/2023 Thu 14:00:18.03
#include<bits/stdc++.h>
using namespace std;
int check(int x,bool c = 0,bool d = 0) {
    if(x == 0) {
        return c;
    }
    int ans = 0;
    if(!c && d) ans += check(x - 1,1,1);
    if(!d) ans += check(x - 1,c,1);
    ans += check(x - 1,c,0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    cout<<check(n,0,0);
    return 0;
}