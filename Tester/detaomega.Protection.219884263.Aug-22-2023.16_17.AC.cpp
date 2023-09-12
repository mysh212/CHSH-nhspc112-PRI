#include <bits/stdc++.h>
using namespace std;


const int maxn = 1e5 + 5;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> vec[i].second;
    }

    sort (vec.begin(), vec.end(), [](pair<int,int> a, pair<int,int> b) {
        if (a.second - a.first == b.second - b.first) {
            return a.first < b.first;
        }
        return a.second - a.first > b.second - b.first;
    });

    int cnt = 0;
    // for (auto [x, y] : vec) {
    //     cout << x << " " << y << endl;
    // }
    for (auto [x, y] : vec) {
        cnt += y;
        if (cnt > x) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;

}