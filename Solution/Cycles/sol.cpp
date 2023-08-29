#include <bits/stdc++.h>

namespace std {

template<class Fun>
class y_combinator_result {
  Fun fun_;
public:
  template<class T>
  explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

  template<class ...Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

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

constexpr int md = 9901;

using Mint = mint<md>;

using lint = long long;

Mint fact[301], power[16];

void solve() {
  int n, k;
  cin >> n >> k;

  vector<array<int, 2>> edges(k);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> edges[i][j];
      --edges[i][j];
    }
  }

  Mint ans = 0;

  for (int s = 0; s < (1 << k); s++) {
    vector<vector<int>> adj(n);
    for (int i = 0; i < k; i++) if (s >> i & 1) {
      auto [u, v] = edges[i];
      adj[u].push_back(v);
      adj[v].push_back(u);
    } 

    int valid = 1;
    for (int i = 0; i < n; i++) {
      valid &= adj[i].size() <= 2;
    }
    if (!valid) {
      continue;
    }

    vector<int> vis(n);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      if (adj[i].empty() || vis[i]) {
        x += adj[i].empty();
        continue;
      }

      int done = 0;
      vector<int> path;
      y_combinator([&](auto self, int v, int p) -> void {
        if (done) {
          return;
        }
        path.push_back(v);
        if (vis[v]) {
          done = 1;
          return;
        }
        vis[v] = 1;
        for (int u : adj[v]) {
          if (u == p) {
            continue;
          }
          self(u, v);
        }
      }) (i, -1);

      if (path[0] == path.back() && int(path.size()) != n + 1) {
        valid = 0;
        break;
      }
      y++;
    }
    if (!valid) {
      continue;
    }

    ans += fact[x + y - 1] * power[y] * (__builtin_popcount(s) & 1 ? -1 : 1);
  }

  cout << ans / 2 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fact[0] = power[0] = 1;
  for (int i = 1; i <= 300; i++) {
    fact[i] = fact[i - 1] * i;
  }
  for (int i = 1; i <= 15; i++) {
    power[i] = power[i - 1] * 2;
  }

  solve();

  return 0;
}