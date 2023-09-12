#include<bits/stdc++.h>
#define endl '\n'
#define OuO ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(auto &[x, y]: a) cin >> x;
    for(auto &[x, y]: a) cin >> y;
    sort(a.begin(), a.end());

    int sum = 0;
    for(auto [x, y]: a){
        sum += y;
        if(sum > x){
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
}