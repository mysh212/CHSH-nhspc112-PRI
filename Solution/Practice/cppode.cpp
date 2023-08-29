#include<bits/stdc++.h>
using namespace std;
const int R = ((int) 1e9) + 7;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    if(n == 2) {
        cout<<1;
        return 0;
    }
    vector<int>f(n);
    for(int i = 0;i<n;i++) {
        if(i == 0) f.at(0) = 1;
        else if(i == 1) f.at(1) = 2;
        else {
            f.at(i) = f.at(i - 1) + f.at(i - 2);
            f.at(i) = f.at(i) % R;
        }
    }
    long long ans = 0;
    for(int i = 1;i<=n - 3;i++) {
        ans = ans + (f.at(i - 1) * f.at(n - i - 3)) % R;
    }
    ans = ans + (f.at(n - 3) << 1);
    ans = ans % R;
    cout<<ans;
    return 0;
}