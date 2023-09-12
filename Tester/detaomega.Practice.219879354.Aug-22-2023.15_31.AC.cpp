#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
int dp[maxn][2], prefixSum1[maxn], prefixSum2[maxn];
int32_t main() {
    int n;
    cin >> n; 
    dp[1][0] = 1;
    dp[0][0] = 1;
    prefixSum1[0] = 1;
    prefixSum1[1] = 2;
    for (int i = 2; i <= n; i++) {
        dp[i][1] = dp[i - 1][0];
        
        dp[i][1] = (dp[i][1] + prefixSum2[i - 2]) % mod;
        dp[i][0] = (dp[i][0] + prefixSum1[i - 2]) % mod;

        prefixSum1[i] = (prefixSum1[i - 1] + dp[i][0]) % mod;
        prefixSum2[i] = (prefixSum2[i - 1] + dp[i][1]) % mod;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i][1]) % mod;
    }

    cout << ans << "\n";

}