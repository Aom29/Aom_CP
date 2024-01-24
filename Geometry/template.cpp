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

const double SIZE = 1e5 + 1,INF = 1e15 + 1;

double compare3points(pair<double, double> a, pair<double, double> b, pair<double, double> c){
    double m = (c.se - a.se) / (c.fi - a.fi);
    return (abs(-m*(b.fi)+b.se+m*(a.fi)-b.se))/(sqrt(pow(m,2)+1));
}

void solve(){
    int n; cin >> n;
    vector<pair<double, double>> points(n);
    forn(i, n)
        cin >> points[i].fi >> points[i].se;
    forn(i, n)
        cout << points[i].fi << points[i].se << endl;
    double ans = INF;
    forn(i, n-2){
        ans = min(compare3points(points[i], points[i+1], points[i+2]), ans);
    }
    ans = min(compare3points(points[n-2], points[n-1], points[0]), ans);
    ans = min(compare3points(points[n-1], points[0], points[1]), ans);
    
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}