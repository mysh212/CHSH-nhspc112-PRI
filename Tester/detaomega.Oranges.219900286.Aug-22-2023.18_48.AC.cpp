#include <bits/stdc++.h>
using namespace std;


const int maxn = 1e5 + 5;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n + 5);

    for (int i = 1; i <= n; i++) {
        cin >> vec[i];    
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int mx = vec[i];
        for (int j = i; j <= n; j++) {
            mx = min(mx, vec[j]);
            ans = max(ans, mx * (j - i + 1));
        }
    }
    cout << ans << "\n";

}