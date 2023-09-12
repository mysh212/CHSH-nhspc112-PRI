#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int md = (int) 1e9 + 7;

inline void add(int& a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline int mul(int a, int b) {
  return (int) ((i64) a * b % md);
}

inline int inverse(int x) {
  int k = md - 2;
  int res = 1;
  while (k > 0) {
    if (k & 1)
      res = mul(res, x);
    x = mul(x, x);
    k >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> f(n, 1);
  vector<int> inv(n, 1);
  for (int i = 1; i < n; i++) {
    f[i] = mul(i, f[i - 1]);
    inv[i] = inverse(f[i]);
    assert(mul(f[i], inv[i]) == 1);
  }

  int ans = 0;
  for (int d = 1; d <= n / 2; d++) {
    int k = n - d;
    int C = mul(mul(f[k], inv[k - d]), inv[d]);
    add(ans, mul(C, d));
  }
  cout << ans << '\n';

  return 0;
}