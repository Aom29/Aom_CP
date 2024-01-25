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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<p2i> vp2i;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

void solve(){
    int n, p, k; cin >> n >> p >> k;
    string a;
    cin >> a;
    int x, y; cin >> x >> y;
    vi dp(n, INF);
    forr(i, p-1, n-1){
        if(i - k < 0){
            dp[i] = (i+1-p)*y;
        }
        else{
            dp[i] = min(((i+1-p)*y), dp[i-k]);
        }

        if(a[i] == '0')
            dp[i] += x;
    }

    int ans = INF;
    forn(i, k){
        ans = min(ans, dp[n-1-i]);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}