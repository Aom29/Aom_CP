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

const ld SIZE = 1e5 + 1,INF = 1e8 + 1;
ld x, y;

pair<ld,ld> fraction(ld b){
    ld a = (x*b)/(y);
    //cout << a - round(a) << endl;
    if(abs(a - round(a)) == (ld)0.5){
        a = floor(a);
    }
    else
        a = round(a);
    return {a, b};
}

void solve(){
    int n; cin >> x >> y >> n;
    ld mindifval = INF;
    pair<ld,ld> ans;
    forr(i, 1, n){
        pair<ld,ld> frac = fraction((ld)i);
        ld partialdifval = abs(x/y - frac.fi/frac.se);
        if(partialdifval < mindifval){
            mindifval = partialdifval;
            ans = frac;
        }
    }

    cout << ans.fi << "/" << ans.se;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

// int t; cin >> t;

// while(t--)
        solve();

    return 0;
}