// https://codeforces.com/contest/294/problem/A

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

bool valid(int a, int n){
    return(a > 0 && a <= n);
}

void solve(){
    int n; cin >> n;
    int m;
    int x, y;
    vi a(n+1);
    forn(i, n)
        cin >> a[i+1];
    cin >> m;
    while(m--){
        cin >> x >> y;
        if(valid(x-1, n)){
            a[x-1] += y - 1;
        }
        if(valid(x+1, n)){
            a[x+1] += a[x] - y;
        }

        a[x] = 0;

    }

    forn(i, n){
        cout << a[i+1] << endl;
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