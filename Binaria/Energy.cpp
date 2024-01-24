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
vector<ld> a(SIZE);

bool valid(ld n, ld k, ld maxi){
    ld faltan = 0, sobran = 0;
    forn(i, n){
        if(a[i] - maxi > 0)
            sobran += a[i] - maxi;
        else
            faltan += maxi - a[i];
    }

    ld transferir = (faltan)/(1-((k)/100));
    return sobran >= transferir;
}

void solve(){
    ld n, k; cin >> n >> k;
    forn(i, n)
        cin >> a[i];
    ld eps = 1e-7;
    ld l = 0, r = 1e18;
    while(l <= r - eps){
        ld m = (l+r)/2;
        if(valid(n, k , m))
            l = m;
        else
            r = m - eps;
    }

    cout << setprecision(15) << l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}