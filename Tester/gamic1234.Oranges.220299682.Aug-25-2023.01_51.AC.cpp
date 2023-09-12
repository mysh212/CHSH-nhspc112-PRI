#include<bits/stdc++.h>
#define endl '\n'
#define OuO ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;

    ll ans = 0;
    for(int i = 0; i < n; ++i){
        int mn = INT_MAX;
        for(int j = i; j < n; ++j){
            mn = min(mn, a[j]);
            ans = max(ans, 1LL * mn * (j - i + 1));
        }
    }

    cout << ans;
}