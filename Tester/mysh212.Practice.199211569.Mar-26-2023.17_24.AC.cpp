// Author : ysh
// 03/23/2023 Thu 14:00:18.03
#include<bits/stdc++.h>
using namespace std;
const int R = ((int) 1e9) + 7;
vector<int>mark;
#define int long long
int check(int x,bool c = 0,bool d = 0) {
    if(x == 0) {
        return c;
    }
    if(mark.at(((x - 1) << 2) + ((int) c << 1) + ((int) d)) != -1) return mark.at(((x - 1) << 2) + ((int) c << 1) + ((int) d));
    int ans = 0;
    if(!c && d) ans += check(x - 1,1,1);
    if(!d) ans += check(x - 1,c,1);
    ans += check(x - 1,c,0);
    return mark.at(((x - 1) << 2) + ((int) c << 1) + ((int) d)) = ans % R;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    mark.resize(n << 2,-1);
    cout<<check(n,0,0);
    return 0;
}