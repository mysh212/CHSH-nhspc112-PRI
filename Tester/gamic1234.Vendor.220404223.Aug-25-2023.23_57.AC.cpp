#include<bits/stdc++.h>
#define endl '\n'
#define OuO ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define pii pair<int, int>
using namespace std;
const int dx[4] =  {1, -1, 0, 0};
const int dy[4] =  {0, 0, 1, -1};
vector<pii> p;

long double dist(pii a, pii b){
    return sqrtl(1LL * (a.first - b.first) * (a.first - b.first) + 1LL * (a.second - b.second) * (a.second - b.second));
}

long double cal(pii v){
    long double ret = 0;
    for(auto x: p){
        ret += dist(x, v);
    }
    return ret;
}

signed main(){OuO
    int n;
    cin >> n;
    p.resize(n);
    for(auto &[x, y]: p) cin >> x >> y;
    int x = 0, y = 0;
    for(int i = 21; ~i; --i){
        for(int k = 0; k < 5; ++k){
            for(int j = 0; j < 4; ++j){
                if(cal({x + (1 << i) * dx[j], y + (1 << i) * dy[j]}) < cal({x + ((1 << i) - 1) * dx[j], y + ((1 << i) - 1) * dy[j]})){
                    x = x + (1 << i) * dx[j];
                    y = y + (1 << i) * dy[j];
                }
            }
        }
    }
    cout << x << ' ' << y;
}