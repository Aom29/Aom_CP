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

ld dist(ld x1, ld y1, ld x2, ld y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

void solve(){
    ld ax, ay, bx, by, ra, rb;
    cin >> ax >> ay >> ra >> bx >> by >> rb;
    cout << setprecision(15);

    if(dist(ax, ay, bx, by) < ra && ra > rb){
        cout << max((ld)0, (ra - dist(ax, ay, bx, by) - rb)/2);
    }

    else if(dist(ax, ay, bx, by) < rb){
        cout << max((ld)0, (rb - dist(ax, ay, bx, by) - ra)/2);
    }

    else
    cout << max((ld)0, (dist(ax, ay, bx, by) - ra - rb)/2);

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}