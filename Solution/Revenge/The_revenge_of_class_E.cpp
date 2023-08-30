#include<bits/stdc++.h>
#define endl '\n'
#define OuO ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;

vector<string> ope[2];
string cha(int n){
    if(n == 0) return "+";
    if(n == 1) return "-";
    return "*";
}

void solve(){
    vector<int> nums(3);
    string s("");
    for(auto &x: nums){
        cin >> x;
        s.push_back((char)(x + '0'));
    }
    sort(s.begin(), s.end());
    set<int> se;
    do{
        for(int i = 1; i < 3; ++i){
            string s1 = s.substr(0, i), s2 = s.substr(i, 3 - i);
            int a = stoi(s1), b = stoi(s2);
            for(auto x: ope[0]){
                int num = 0;
                if(x == "+") num = a + b;
                else if(x == "-") num = a - b;
                else num = a * b;

                if(num >= 0){
                    if(!se.count(num)){
                        cerr << a << x << b << '=' << num << endl;
                    }
                }
                if(num >= 0) se.insert(num);
            }
        }
        for(auto x: ope[1]){
            int num = 0, a = s[0] - '0', b = s[1] - '0', c = s[2] - '0';

            if(x[0] == '+' && x[1] == '+') num = a + b + c;
            if(x[0] == '+' && x[1] == '-') num = a + b - c;
            if(x[0] == '+' && x[1] == '*') num = a + b * c;
            if(x[0] == '-' && x[1] == '+') num = a - b + c;
            if(x[0] == '-' && x[1] == '-') num = a - b - c;
            if(x[0] == '-' && x[1] == '*') num = a - b * c;
            if(x[0] == '*' && x[1] == '+') num = a * b + c;
            if(x[0] == '*' && x[1] == '-') num = a * b - c;
            if(x[0] == '*' && x[1] == '*') num = a * b * c;
            
            if(num >= 0){
                if(!se.count(num)){
                    cerr << a << x[0]  << b  << x[1] << c << '=' << num << endl;
                }
            }
            if(num >= 0) se.insert(num);
        }
    }while(next_permutation(s.begin(), s.end()));
    cout << (int)se.size() << endl;
}

signed main(){OuO
    ope[0] = {"+", "-", "*"};
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            ope[1].push_back(cha(i) + cha(j));
        }
    }

    int tt;
    cin >> tt;
    while(tt--) solve();
}
