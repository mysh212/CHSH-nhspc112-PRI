#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int md = (int) 1e9 + 7;

struct Z {
  int x = 0;

  Z(int x) : x(x) {}

  inline void operator += (const Z rhs) {
    x += rhs.x;
    if (x >= md) x -= md;
  }

  inline void operator *= (const Z rhs) {
    x = 1LL * x * rhs.x % md;
  }

  friend Z operator * (const Z lhs, const Z rhs) {
    Z res = lhs;
    res *= rhs;
    return res;
  }

  friend ostream &operator << (ostream& os, const Z& a) {
    return os << a.x;
  }
};

inline Z inverse(Z x) {
  int k = md - 2;
  Z res = 1;
  while (k > 0) {
    if (k & 1)
      res = res * x;
    x = x * x;
    k >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<Z> f(n, 1);
  vector<Z> inv(n, 1);
  for (int i = 1; i < n; i++) {
    f[i] = (Z) i * f[i - 1];
    inv[i] = inverse(f[i]);
  }

  Z ans = 0;
  for (int d = 1; d <= n / 2; d++) {
    int k = n - d;
    Z C = f[k] * inv[k - d] * inv[d];
    ans += (Z) d * C;
  }
  cout << ans << '\n';

  return 0;
}