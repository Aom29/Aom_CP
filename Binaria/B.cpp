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
    vi a(n);
    vi pre(n+1);
    pre[0] = 0;
    forn(i, n){
        cin >> a[i];
        pre[i+1] = pre[i] + a[i];
    }
    
    int m;
    cin >> m;
    int q;

    while(m--){
        cin >> q;
        int l=1, r=n;
        while(l<=r){
            int m = (l+r)/2;
            if(q <= pre[m]){
                r = m - 1;
            }
            else{
                l = m+1;
            }
        }

        cout << r+1 << endl;
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