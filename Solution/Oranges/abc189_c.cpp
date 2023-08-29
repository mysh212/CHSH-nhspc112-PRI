#include <bits/stdc++.h>

using namespace std;

using lint = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = 0;
  for (int l = 0; l < n; l++) {
    int mn = a[l];
    for (int r = l; r < n; r++) {
      mn = min(mn, a[r]);
      ans = max(ans, (r - l + 1) * mn);
    }
  }
  cout << ans << '\n';
  
  return 0;
}