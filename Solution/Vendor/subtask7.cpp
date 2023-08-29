// Author : ysh
// 2023/08/03 Thu 14:22:59
#include<bits/stdc++.h>
using namespace std;
#define dt(i,j,k,l) ((i - k) * 1LL * (i - k) + (j - l) * 1LL * (j - l))
long double alldt(vector<pair<int,int>>&f,int x,int y) {
    long double ans = 0;
    for(auto &i : f) {
        ans = ans + sqrtl(abs(dt(i.first,i.second,x,y)));
    }
    return ans;
}
int check(vector<pair<int,int>>&f,int x,int l,int r) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    bool c = alldt(f,x,mid) > alldt(f,x,mid + 1);
    if(c) return check(f,x,mid + 1,r);
    else return check(f,x,l,mid);
}
int ck(vector<pair<int,int>>&f,int l,int r) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    int left = check(f,mid,-int(1e6),int(1e6));
    int right = check(f,mid + 1,-int(1e6),int(1e6));
    bool c = alldt(f,mid,left) > alldt(f,mid + 1,right);
    if(c) return ck(f,mid + 1,r);
    else return ck(f,l,mid);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    for(auto &i : f) {
        cin>>i.first>>i.second;
    }
    
    int x = ck(f,-int(1e6),int(1e6));
    int y = check(f,x,-int(1e6),int(1e6));

    cout<<x<<" "<<y<<"\n";
    return 0;
}