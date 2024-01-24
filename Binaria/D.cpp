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
    lli n; cin >> n;

    lli l, r, m;
    int ans = 0;

    while(n > 1){
        l = 1;
        r = n;
        while(l <= r){
            m = (l+r)/2;
            if(((3*m*m) + m)/2 <= n){
                l = m+1;
            }
            else{
                r = m-1;
            }
        }

        n -= ((3*(l-1)*(l-1)) + (l-1))/2;
        if(n >= 0 && (l-1) > 0){
            ans++;
        }
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