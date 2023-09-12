#include<bits/stdc++.h>
using namespace std;
const int R = (int) 1e9 + 7;
#define hck(i,j) check(i + j - 1,j)
#define int long long
int fp(int a,int b) {
    if(b == 0) return 1;
    int tmp = fp(a,b >> 1);
    if(b & 1) return (((tmp * tmp) % R) * a) % R;
    return (tmp * tmp) % R;
}
vector<int>mark({1});
int fl(int x) {
    if(mark.size() >= x + 1) return mark.at(x);
    mark.push_back((fl(x - 1) * x) % R);
    return mark.at(x);
}
int check(int a,int b) {
    return (((fl(a) * fp(fl(a - b),R - 1 - 1)) % R) * fp(fl(b),R - 1 - 1)) % R;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    n = n - 1;
    int ans = 0;
    for(int i = (n + 1) >> 1;i>=1;i--) {
        int left = n - (i - 1) - i;
        ans = ans + hck(i + 1,left) * i;
        ans = ans % R;
    }
    cout<<ans;
    return 0;
}