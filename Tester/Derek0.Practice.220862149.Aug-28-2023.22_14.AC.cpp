#include <bits/stdc++.h>

using namespace std;
template <int mod>
struct mint {
  unsigned int _v;
  mint() : _v(0) {}
  template <class T>
  mint(T v) {
    long long x = (long long)(v % (long long)(umod()));
    if (x < 0) x += umod();
    _v = (unsigned int)(x);
  }
  mint(bool v) { _v = ((unsigned int)(v) % umod()); }

  static constexpr unsigned int umod() { return mod; }
  unsigned int val() const { return _v; }

  mint& operator++() {
    _v++;
    if (_v == umod()) _v = 0;
    return *this;
  }
  mint& operator--() {
    if (_v == 0) _v = umod();
    _v--;
    return *this;
  }
  mint operator++(int) {
    mint result = *this;
    ++*this;
    return result;
  }
  mint operator--(int) {
    mint result = *this;
    --*this;
    return result;
  }

  mint& operator+=(const mint& rhs) {
    _v += rhs._v;
    if (_v >= umod()) _v -= umod();
    return *this;
  }
  mint& operator-=(const mint& rhs) {
    _v -= rhs._v;
    if (_v >= umod()) _v += umod();
    return *this;
  }
  mint& operator*=(const mint& rhs) {
    unsigned long long z = _v;
    z *= rhs._v;
    _v = (unsigned int)(z % umod());
    return *this;
  }
  mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

  mint operator+() const { return *this; }
  mint operator-() const { return mint() - *this; }

  mint pow(long long n) const {
    assert(n >= 0);
    mint x = *this, r = 1;
    for (; n; n >>= 1) {
        if (n & 1) r *= x;
        x *= x;
    }
    return r;
  }

  mint inv() const { return pow(umod() - 2); }

  friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
  friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
  friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
  friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
  friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
  friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }

  template<int T>
  friend istream& operator >> (istream &in, mint<T> &x) { return in >> x._v; }
  template<int T>
  friend ostream& operator << (ostream &out, mint<T> const& x) { return out << x._v; }
};

const int md = (int) 1e9 + 7;

using Mint = mint<md>;

typedef long long ll;

const int _ = 1000010;

Mint f[_][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  f[1][0] = f[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i][0] = f[i - 1][0] + f[i - 1][1];
    f[i][1] = f[i - 1][0];
  }

  Mint ans = 0;
  for (int i = 1; i < n; i++) {
    ans += f[i][1] * f[n - i][1];
  }
  cout << ans << '\n';

  return 0;
}