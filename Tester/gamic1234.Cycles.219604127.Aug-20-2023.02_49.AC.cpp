#include<bits/stdc++.h>
#define endl '\n'
#define OuO ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define pii pair<int, int>
#define in2 4951
using namespace std;
const ll mod = 9901;

struct DSU{
    vector<int> parent, sz;
    void init(int n){
        parent.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; ++i){
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int Find(int x){
        return parent[x] = ((parent[x] == x) ? x : Find(parent[x]));
    }

    void join(int a, int b){
        int x = Find(a), y = Find(b);
        if(x == y) return;
        if(sz[x] > sz[y]) swap(x, y);
        parent[x] = y;
        sz[y] += sz[x];
    }
};

signed main(){OuO
    int fac[301] = {1}, n, k;
    ll ans = 1;
    for(int i = 1; i <= 300; ++i) fac[i] = fac[i - 1] * i % mod;
    cin >> n >> k;
    vector<pii> fb(k);
    for(int i = 3; i <= n - 1; ++i) ans = 1LL * ans * i % mod;
    for(auto &[x, y]: fb){
        cin >> x >> y;
        if(x > y) swap(x, y);
        --x, --y;
    }
    sort(fb.begin(), fb.end());
    fb.erase(unique(fb.begin(), fb.end()), fb.end());
    k = fb.size();
    vector<ll> v(k + 1, 0);

    for(int s = 1; s < (1 << k); ++s){
        int cnt = 0, tw = -1;
        DSU dsu;
        dsu.init(n);
        vector<int> num(n, 0);
        bool flag = false;
        for(int i = 0; i < k; ++i){
            if((s >> i) & 1){
                ++cnt;
                if(dsu.sz[dsu.Find(fb[i].first)] == 1 && dsu.sz[dsu.Find(fb[i].second)] == 1) ++tw;
                if(dsu.sz[dsu.Find(fb[i].first)] > 1 && dsu.sz[dsu.Find(fb[i].second)] > 1) --tw;
                if(dsu.Find(fb[i].first) == dsu.Find(fb[i].second)) flag = true;
                dsu.join(dsu.Find(fb[i].first), dsu.Find(fb[i].second));
                num[fb[i].first]++;
                num[fb[i].second]++;
                if(num[fb[i].first] > 2) flag = true;
                if(num[fb[i].second] > 2) flag = true;
            }
        }
        if(flag){
            for(int i = 0; i < n; ++i){
                if(num[i] != 2) break;
                if(i == n - 1) flag = false;
            }
        }
        if(flag) continue;
        // if(cnt == 3){
        //     cout << s << endl;
        // }
        ll tmp;
        if(n - cnt - 1 < 0) tmp = 1;
        else tmp = 1LL * fac[n - cnt - 1] * ((1 << tw)) % mod;
        v[cnt] = (v[cnt] + tmp) % mod;
    }
    // if(k >= n) v[n] += 1LL * fac[n - 1] * in2 % mod;
    for(int i = 1; i <= k; ++i){
        // cerr << i << ':' << v[i] << endl;
        if(i & 1) ans = (ans - v[i] + mod) % mod;
        else ans = (ans + v[i]) % mod;
    }

    cout << ans % mod;
}