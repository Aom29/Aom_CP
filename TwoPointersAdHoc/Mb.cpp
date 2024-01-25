#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
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

void solve(){
    int n, m; cin >> n >> m;
    vi a(n), b(m);
    forn(i, n)
        cin >> a[i];
    forn(i, m)
        cin >> b[i];

    sort(all(a));
    sort(all(b));
    
    int tmin = INF;
    forn(i, n){
        int l = 0, r = m-1;
        while(l <= r){
            int mid = (l+r)/2;
            tmin = min(tmin, abs(a[i]-b[mid]));
            if(tmin == 0){
                cout << "0";
                return;
            }
            if(a[i] > b[mid]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
    }

    cout << tmin;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //int t; cin >> t;

    //while(t--)
        solve();

    return 0;
}