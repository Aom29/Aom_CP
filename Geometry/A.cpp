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

const double SIZE = 1e5 + 1,INF = 2e9 + 5;
int n; 

bool valid(vp2i &puntos, lli y1){
    forn(i,n){
        if(puntos[i].fi + puntos[i].se > y1)
            return false;
    }
    return true;
}

void solve(){
    cin >> n;
    vp2i puntos(n);
    forn(i, n)
        cin >> puntos[i].fi >> puntos[i].se;
    lli l = 0, r = INF;
    while(l <= r){
        lli mid = (l+r)/2;
        if(!valid(puntos, mid))
            l = mid+1;
        else
            r = mid-1;
    }
    cout << r+1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}