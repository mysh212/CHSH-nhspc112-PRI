#include<bits/stdc++.h>
#define endl '\n'
#define OuO ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;

void solve(){
    ll k;
    cin >> k;
    vector<int> nums;
    while(k){
        nums.push_back(k % 9);
        k /= 9;
    }
    int i = 0;
    ll ans = 0;
    for(auto it = nums.begin(); it != nums.end(); it++, i++){
        int x = *it;
        if(x >= 7) ++x;
        ans += x * pow(10, i);
    }
    cout << ans << endl;
}

signed main(){OuO
    int tt;
    cin >> tt;
    while(tt--) solve();
}