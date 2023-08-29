// Author : ysh
// 01/23/2023 Mon 16:49:56.64
#include<bits/stdc++.h>
using namespace std;
#define ri(i,j) (((((long long) rand() << 16) + rand()) % (j - i + 1)) + i)
int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = atoi(argv[1]);
    int r = atoi(argv[2]);
    int t = atoi(argv[3]);
    srand(r);
    if(t == 2) cout<<ri(2,n)<<"\n";
    if(t == 1) cout<<n<<"\n";
    return 0;
}