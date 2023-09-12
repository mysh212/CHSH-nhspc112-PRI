#include<bits/stdc++.h>
#define endl '\n'
#define OuO ios::sync_with_stdio(0);cin.tie(0);
#define int long long
using namespace std;
const int maxn = 1e6 + 5, mod = 1e9 + 7;

int dp[2][maxn];

int f(int i){
    if(i <= 0) return 1;
    return (dp[0][i] + dp[1][i]) % mod;
}

signed main(){
    int n, ans = 0;
    cin >> n;

    dp[0][1] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= n; ++i){
        dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % mod;
        dp[1][i] = dp[0][i - 1];
    }

    for(int i = -1; i <= n - 3; ++i){
        ans = (ans + (f(i) * f(n - 4 - i)) % mod) % mod;
    }
    
    cout << ans;
}