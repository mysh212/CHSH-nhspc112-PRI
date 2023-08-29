#include<bits/stdc++.h> 
# 1 "ccb.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "ccb.cpp"



using namespace std;







# 1 "C:\\Users\\ysh00\\Coding\\library/table" 1
using namespace std;
template<typename T>
T minf(T a,T b) {
    return min(a,b);
};

template<typename T>
struct table{
    vector<vector<T>>f;
    function<T(T,T)> c;
    long long n;

    table(vector<T>&v,function<T(T,T)> r = ::minf<T>) {
        this->n = v.size();
        c = r;

        f.resize(n,vector<T>(__lg(n) + 1));
        for(long long i = 0;i<n;i++) {
            f[i][0] = v[i];
        }
        for(long long i = 1;i<=__lg(n);i++) {
            for(long long j = 0;j + (1 << i) <= n;j++) {
                f[j][i] = c(f[j][i - 1],f[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    T get(long long l,long long r) {
        if(l > r) swap(l,r);
        long long ll = __lg(r - l + 1);
        return c(f[l][ll],f[r - (1 << ll) + 1][ll]);
    }
};
# 13 "ccb.cpp" 2
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;cin>>n;
    vector<long long>f(n),g(n + 1);
    for(long long &i : f) {
        cin>>i;
    }

    for(long long i = 1;i<=n;i++) {
        g.at(i) = g.at(i - 1) + f.at(i - 1);
    }

    table<long long>mmax(g,[] (long long a,long long b) {
        return max(a,b);
    }),mmin(g);

    vector<long long>mark,left(n),right(n);
    long long t = 0;
    for(long long &i : f) {
        while(!mark.empty() && f.at(mark.back()) <= i) mark.pop_back();
        left.at(t) = (mark.empty() ? -1 : mark.back() + 1);
        mark.push_back(t++);
    }
    mark.clear();

    for(long long i = n - 1;i>=0;i--) {
        while(!mark.empty() && f.at(mark.back()) <= f.at(i)) mark.pop_back();
        right.at(i) = (mark.empty() ? n - 1 : mark.back() - 1);
        mark.push_back(i);
    }

    long long ans = 0;
    for(long long i = 0;i<n;i++) {
        if(f.at(i) >= 0) ans = max(ans,mmax.get(i + 1,right.at(i) + 1) - mmin.get(left.at(i) + 1,i) - f.at(i));
    }
    '*';
    '*';
    '*';
    '*';

    cout<<ans;
    return 0;
}
