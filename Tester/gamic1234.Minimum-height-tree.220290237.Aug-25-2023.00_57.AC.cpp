#include<bits/stdc++.h>
#define endl '\n'
#define OuO ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);

    auto bfs = [&](int s){
        vector<vector<int>> d(2, vector<int>(n, -1));
        queue<int> q;
        q.push(s);
        d[0][s] = 0;

        while(q.size()){
            int now = q.front();
            q.pop();

            for(auto x: g[now]){
                if(d[0][x] != -1) continue;
                d[0][x] = d[0][now] + 1;
                d[1][x] = now;
                q.push(x);
            }
        }

        return d;
    };

    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto d1 = bfs(0);
    auto s1 = max_element(d1[0].begin(), d1[0].end()) - d1[0].begin();
    auto d2 = bfs(s1);
    auto s2 = max_element(d2[0].begin(), d2[0].end()) - d2[0].begin();
    auto mx = *max_element(d2[0].begin(), d2[0].end());

    int now = s2;
    for(int i = 0; i < (mx >> 1); ++i) now = d2[1][now];

    auto d3 = bfs(now);
    cout << *max_element(d3[0].begin(), d3[0].end());
}