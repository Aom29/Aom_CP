// Olvera Martinez Aaron

#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    vector<int> dp(n+1);
    dp[n] = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = n-1; i >= 0; i--){
        if(a[i]+i == n-1)
            dp[i] = 0;
        else if(a[i]+i < n-1){
            dp[i] = min(dp[i+1]+1, dp[i+a[i]+1]);
        }
        else
            dp[i] = dp[i+1]+1;
    }

    cout << dp[0] << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}