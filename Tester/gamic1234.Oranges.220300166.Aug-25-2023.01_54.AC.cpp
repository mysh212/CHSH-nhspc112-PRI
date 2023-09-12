#include<bits/stdc++.h>
#define endl '\n'
#define OuO ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;
const int maxn = 1e4 + 5;
int spt[15][maxn];

signed main(){OuO
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> spt[0][i];
    }
    for(int i = 1; i < 15; ++i){
        for(int j = 1; j + (1 << (i - 1)) <= n; ++j){
            spt[i][j] = min(spt[i - 1][j], spt[i - 1][j + (1 << (i - 1))]);
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = i ; j <= n; ++j){
            int k = __lg(j - i + 1);
            ans = max(ans, 1LL * (j - i + 1) * min(spt[k][i], spt[k][j - (1 << k) + 1]));
        }
    }

    cout << ans;
}