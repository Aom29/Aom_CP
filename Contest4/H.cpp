#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long lli;
typedef long double ld;
typedef pair<int, int> p2i;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef vector<p2i> vp2i;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

void solve(){
    int n; cin >> n;
    vvi a(2, vi(n));
    vvi dp(2, vi(n, 0));
    forn(i, n)
        cin >> a[0][i];
    forn(i, n)
        cin >> a[1][i];
    dp[0][0] = a[0][0];
    dp[1][0] = a[1][0];

    forn(i, n-2){
        dp[1][i+1] = max(dp[1][i+1], dp[0][i]+a[1][i+1]);
        dp[1][i+2] = max(dp[1][i+2], dp[0][i]+a[1][i+2]);
        dp[0][i+1] = max(dp[0][i+1], dp[1][i]+a[0][i+1]);
        dp[0][i+2] = max(dp[0][i+2], dp[1][i]+a[0][i+2]);
    }

    if(n > 1){
        dp[1][n-1] = max(dp[1][n-1], dp[0][n-2]+a[1][n-1]);
        dp[0][n-1] = max(dp[0][n-1], dp[1][n-2]+a[0][n-1]);
    }
         
    cout << max(dp[1][n-1], dp[0][n-1]);

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}