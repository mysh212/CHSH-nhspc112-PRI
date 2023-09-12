#include<bits/stdc++.h>
#define endl '\n'
#define OuO ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;

bool gl(string a, string b){
    if(a.size() < b.size()) return true;
    if(a.size() > b.size()) return false;
    return a <= b;
}

signed main(){OuO
    int a;
    string b;
    cin >> a >> b;
    if(b[0] == '-') b = b.substr(1);
    int m;
    cin >> m;
    while(m--){
        string k;
        cin >> k;
        if(k[0] == '-') k = k.substr(1);
        if(gl(b, k) && ((b.back() - '0') & 1) == ((k.back() - '0') & 1)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}