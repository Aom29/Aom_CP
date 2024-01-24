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
    int n; cin >> n;
    vi aa(n), bb(n), cc(n);
    int a, b, c;
    multiset<p2i> maxa, maxb, maxc;
    forn(i, 3){
        maxa.insert({0,i});
        maxb.insert({0,i});
        maxc.insert({0,i});
    }
    forn(i, n){
        cin >> a;
        if(a > (*maxa.begin()).fi){
            maxa.erase(*maxa.begin());
            maxa.insert({a, i});
        }
        aa[i] = a;
    }
    forn(i, n){
        cin >> b;
        if(b > (*maxb.begin()).fi){
            maxb.erase(*maxb.begin());
            maxb.insert({b, i});
        }
        bb[i] = b;
    }
    forn(i, n){
        cin >> c;
        if(c > (*maxc.begin()).fi){
            maxc.erase(*maxc.begin());
            maxc.insert({c, i});
        }
        cc[i] = c;
    }
    
    vi va(3), vb(3), vc(3);

    forn(i, 3){
        va[i] = (*maxa.rbegin()).se;
        maxa.erase(maxa.find({(*maxa.rbegin()).fi, (*maxa.rbegin()).se}));
        vb[i] = (*maxb.rbegin()).se;
        maxb.erase(maxb.find({(*maxb.rbegin()).fi, (*maxb.rbegin()).se}));
        vc[i] = (*maxc.rbegin()).se;
        maxc.erase(maxc.find({(*maxc.rbegin()).fi, (*maxc.rbegin()).se}));
    }

    int ans = 0;

    // forn(i, 3){
    //     cout << va[i];
    // }

    for(int x: va){
        for(int y: vb){
            for(int z: vc){
                if(x != y && x != z && y != z){
                    ans = max(ans, aa[x]+ bb[y] + cc[z]);
                }
            }
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