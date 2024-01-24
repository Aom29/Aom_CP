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

const int SIZE = 1e5 + 1,INF = 1e9 + 1;

bool isColineal(int ax, int ay, int bx, int by, int cx, int cy){
    return ((cx-ax)*(by-ay) == (cy-ay)*(bx-ax));
}

void solve(){
    int n; cin >> n;
    int x0, y0; cin >> x0 >> y0;
    int x, y;
    vp2i troops(n);
    vector<bool> marked(n, false);
    forn(i, n){
        cin >> x >> y;
        troops[i] = {x,y};
    }

    int ans = 0;
    forn(i, n){
        if(marked[i])
            continue;
        ans++;
        int px = troops[i].fi;
        int py = troops[i].se;
        marked[i] = true;

        forr(j, i+1, n-1){
            if(!marked[j]){
                if(isColineal(x0, y0, px, py, troops[j].fi, troops[j].se))
                    marked[j] = true;
            }
        }

    }

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