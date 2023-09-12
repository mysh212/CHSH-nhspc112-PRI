#include<bits/stdc++.h>
#define endl '\n'
#define OuO ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;

signed main(){
    int tt;
    cin >> tt;
    while(tt--){
        ll n;
        cin >> n;
        int ans[13] = { };
        for(int i = 0; i < 13; ++i){
            int now = n;
            ans[i] = now - (n / 9) * 9;
            if(ans[i] >= 7) ++ans[i];
            n /= 9;
        }
        bool flag = false;
        for(int i = 12; i >= 0; --i){
            if(ans[i] != 0) flag = true;
            if(flag) cout << ans[i];
        }
        cout << endl;
    }
}