#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans;
    if(a == b)
        ans = 0;
    else if(abs(a-b)%(2*c) == 0){
        ans = abs(a-b)/(2*c);
    }
    else
        ans = (abs(a-b)/(2*c)) + 1;
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}