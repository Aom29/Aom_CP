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
    if(n == 1){
        cout << '1' << endl;
        return;
    }

    // 169
    for(int i = n/2-1; i >= 0; i--){
        cout << '1';
        forn(j, i)
            cout << '0';
        cout << '6';
        forn(j, i)
            cout << '0';
        cout << '9';
        forn(j, n-3-i*2)
            cout << '0';
        cout << endl;
    }

    // 961
    for(int i = n/2-1; i >= 0; i--){
        cout << '9';
        forn(j, i)
            cout << '0';
        cout << '6';
        forn(j, i)
            cout << '0';
        cout << '1';
        forn(j, n-3-i*2)
            cout << '0';
        cout << endl;
    }

    // 169
    cout << "196";
    forn(j, n-3)
        cout << '0';
    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}