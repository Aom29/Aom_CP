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
    lli n, k; cin >> n >> k;
    vector<lli> a(n+1,0), bmax(n+1,0);
    lli ans = 0;
    lli b = 0;
    forn(i, n){
        cin >> a[i];
    }
    forn(i, n){
        cin >> b;
        bmax[i+1] = max(bmax[i], b);
    }

    lli suma = 0;

    forr(i, 0, min(n, k)-1){
        suma += a[i];
        ans = max(suma + (k-i-1)*bmax[i+1], ans);
        // cout << "bmax[i] = " << bmax[i] << endl;
        // cout << "Suma = " << suma << endl;
        // cout << "Ans = " << ans << endl;
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