#include<bits/stdc++.h>
#define endl '\n'
#define OuO ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define L ((pos << 1) + 1)
#define R ((pos << 1) + 2)
using namespace std;

struct S_T{
    struct Node{
        ll sum, pre, suf, ans;
    };
    vector<Node> seg;
    vector<int> a;
 
    Node pull(Node a, Node b){
        Node ret;
        ret.sum = a.sum + b.sum;
        ret.pre = max({0LL, a.sum + b.pre, a.pre});
        ret.suf = max({0LL, b.sum + a.suf, b.suf});
        ret.ans = max({0LL, a.ans, b.ans, a.suf + b.pre, ret.pre, ret.suf});
        return ret;
    }
 
    void build(int l, int r, int pos){
        if(l == r){
            seg[pos] = {a[l], max(a[l], 0), max(a[l], 0), max(a[l], 0)};
            return;
        }
        int mid = (l + r) >> 1;
 
        build(l, mid, L);
        build(mid + 1, r, R);
        seg[pos] = pull(seg[L], seg[R]);
    }
 
    void modify(int l, int r, int q, int pos, int val){
        if(l == r){
            seg[pos] = {val, max(val, 0)};
            return;
        }
        int mid = (l + r) >> 1;
 
        if(q <= mid) modify(l, mid, q, L, val);
        else modify(mid + 1, r, q, R, val);
        seg[pos] = pull(seg[L], seg[R]);
    }

    Node query(int l, int r, int ql, int qr, int pos){
        if(ql <= l && r <= qr) return seg[pos];
        int mid = (l + r) >> 1;
        if(qr <= mid){
            return query(l, mid, ql, qr, L);
        }else if(mid < ql){
            return query(mid + 1, r, ql, qr, R);
        }else{
            return pull(query(l, mid, ql, qr, L), query(mid + 1, r, ql, qr, R));
        }
    }
 
    S_T(int n, vector<int> arr){
        a = arr;
        seg.resize((n << 2), {0, 0, 0, 0});
        build(0, n - 1, 0);
    }
};

signed main(){
    int n;
    cin >> n;
    vector<int> l(n), r(n), a(n);
    deque<int> dq;
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    for(int i = 0; i < n; ++i){
        while(!dq.empty() && a[dq.back()] < a[i]){
            r[dq.back()] = i;
            dq.pop_back();
        }
        dq.push_back(i);
    }
    while(!dq.empty()){
        r[dq.back()] = n;
        dq.pop_back();
    }

    for(int i = n - 1; ~i; --i){
        while(!dq.empty() && a[dq.back()] < a[i]){
            l[dq.back()] = i;
            dq.pop_back();
        }
        dq.push_back(i);
    }
    while(!dq.empty()){
        l[dq.back()] = -1;
        dq.pop_back();
    }

    S_T tree(n, a);

    ll mx = INT_MIN;
    for(int i = 0; i < n; ++i){
        ll ans = 0;
        if(l[i] + 1 <= i - 1) ans += tree.query(0, n - 1, l[i] + 1, i - 1, 0).suf;
        if(i + 1 <= r[i] - 1) ans += tree.query(0, n - 1, i + 1, r[i] - 1, 0).pre;
        mx = max(ans, mx);
    }

    cout << mx;
}