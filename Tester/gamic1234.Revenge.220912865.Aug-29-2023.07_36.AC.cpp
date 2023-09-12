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

signed main(){OuO
    ope[0] = {"+", "-", "*"};
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            ope[1].push_back(cha(i) + cha(j));
        }
    }

    int tt;
    cin >> tt;
    while(tt--){
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
                string a = s.substr(0, i), b = s.substr(i, 3 - i);
                for(auto x: ope[0]){
                    int num = 0;
                    if(x == "+") num = stoi(a) + stoi(b);
                    else if(x == "-") num = stoi(a) - stoi(b);
                    else num = stoi(a) * stoi(b);
                    if(num >= 0) se.insert(num);
                }
            }
            for(int i = 0; i < 3; ++i){
                for(int j = i + 1; j < 2; ++j){
                    string a = s.substr(0, i + 1), b = s.substr(i + 1, (j - i)), c = s.substr(j + 1);
                    for(auto x: ope[1]){
                        int ans = 0, cur = stoi(a);
                        if(x[0] == '+'){
                            ans += cur;
                            cur = stoi(b);
                        }else if(x[0] == '-'){
                            ans -= cur;
                            cur = stoi(b);
                        }else{
                            cur *= stoi(b);
                        }
                        if(x[1] == '+'){
                            ans += cur;
                            cur = stoi(c);
                        }else if(x[1] == '-'){
                            ans -= cur;
                            cur = stoi(c);
                        }else{
                            cur *= stoi(c);
                        }
                        ans += cur;
                        if(ans >= 0) se.insert(ans);
                    }
                }
            }
            // for(auto x: ope[2]){
            //     int ans = 0, cur = s[0] - '0';
            //     for(int i = 0; i < 3; ++i){
            //         if(x[i] == '+'){
            //             ans += cur;
            //             cur = s[i + 1] - '0';
            //         }else if(x[i] == '-'){
            //             ans -= cur;
            //             cur = s[i + 1] - '0';
            //         }else{
            //             cur *= (s[i + 1] - '0');
            //         }
            //     }
            //     ans += cur;
            //     if(ans >= 0) se.insert(ans);
            // }
        }while(next_permutation(s.begin(), s.end()));
        cout << (int)se.size() << endl;
    }

}