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
int n;
lli s;

bool nmed(vp2i &v, lli med){
    int ok = 0;
    vp2i vpmed;
    lli q = s;

    forn(i, n){
        if(v[i].se < med){
            q -= v[i].fi;
        }else if(v[i].fi >= med){
            ok++;
            q -= v[i].fi;
        }else{
            vpmed.pb(v[i]);
        }
    }
    
    sort(all(vpmed));
    int f = max(((n+1)/2) - ok, 0);
    for(int i = vpmed.size() - 1; i >= 0; i--){
        if(f > 0){
            q -= med;
            f--;
        }
        else{
            q -= vpmed[i].fi;
        }
    }

    return f == 0 && q >= 0;
}

void solve(){
    cin >> n >> s;
    vp2i v(n);
    forn(i, n){
        cin >> v[i].fi >> v[i].se;
    }
    
    lli l = 0, r = s;
    lli maxmed = 0;
    while (l <= r){
        lli med = (l+r)/2;
        if(nmed(v, med)){
            maxmed = max(med, maxmed);
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    
    cout << maxmed << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}