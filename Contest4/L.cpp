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

lli gauss(lli n, lli k){
    // cout << k*n-(n*n)/2+n/2 << endl;
    return k*n-(n*n)/2+n/2;
}

void solve(){
    lli n; cin >> n;
    lli k; cin >> k;

    if(n == 1){
        cout << "0";
        return;
    }

    lli l = 1, r = k-1;

    while(l<=r){
        lli m = (l+r)/2;
        if(1 + gauss(m, k-1) >= n){
            r = m-1;
        }
        else
            l = m+1;
    }

    if(l == k){
        cout << "-1";
        return; 
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