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

void solve(){
    int cases; cin >> cases;
    int sx, sy; cin >> sx >> sy;
    int x, y;
    int n = 0, w = 0, e = 0, s = 0;
    forn(i, cases){
        cin >> x >> y;
        if(y > sy)
            n++;
        if(y < sy)
            s++;
        if(x > sx)
            e++;
        if(x < sx)
            w++;
    }

    if(n >= s && n >= w && n >= e){
        cout << n << endl;
        cout << sx << ' ' << sy+1;
    }
    else if(e >= s && e >= w){
        cout << e << endl;
        cout << sx+1 << ' ' << sy;
    }
    else if(s >= w){
        cout << s << endl;
        cout << sx << ' ' << sy-1;
    }
    else{
        cout << w << endl;
        cout << sx-1 << ' ' << sy;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}