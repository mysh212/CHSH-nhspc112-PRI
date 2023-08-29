#include <bits/stdc++.h>

using namespace std;

using lint = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> adj(n);
  vector<int> deg(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;

    ++deg[u]; ++deg[v];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 1) {
      q.push(i);
    }
  }

  vector<int> dist(n);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
      if (--deg[u] == 1) {
        dist[u] = dist[v] + 1;
        q.push(u);
      }
    }
  }

  int mx = *max_element(dist.begin(), dist.end());
  mx += count(dist.begin(), dist.end(), mx) >= 2;
  
  cout << mx << '\n';
  
  return 0;
}