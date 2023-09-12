// Author : ysh 
// 2023/08/12 Sat 16:23:21 
#include<bits/stdc++.h> 
using namespace std; 
const int xx[] = {-1,0,1,0}; 
const int yy[] = {0,1,0,-1}; 
vector<pair<int,int>>f; 
#define dt(i,j) sqrtl((i.first * 1LL - j.first) * (i.first - j.first) + (i.second * 1LL - j.second) * (i.second - j.second)) 
double alldt(pair<int,int>j) { 
    double ans = 0; 
    for(auto &i : f) { 
        ans = ans + dt(i,j); 
    } 
    return ans; 
} 
int main() { 
    ios::sync_with_stdio(false); 
    cin.tie(0); 
  
    int n;cin>>n; 
    f = vector<pair<int,int>>(n); 
    for(auto &i : f) { 
        cin>>i.first>>i.second; 
    } 
  
    int mask = (1 << 20); 
    pair<int,int>now = make_pair(0,0); 
    double ans = alldt({0,0}); 
  
    while(mask != 0) { 
        for(int j = 1;j<=2;j++) { 
            for(int i = 0;i<=3;i++) { 
                auto pre = make_pair(now.first + (xx[i] * mask),now.second + (yy[i] * mask)); 
                auto t = alldt(pre); 
                if(t < ans) { 
                    ans = t; 
                    now = pre; 
                } 
            } 
        } 
        mask = mask >> 1; 
    } 
    cout<<now.first<<" "<<now.second<<"\n"; 
    return 0; 
}