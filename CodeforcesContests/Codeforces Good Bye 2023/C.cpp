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
    forn(i, n){
        cin >> a[i];
    }

    int pares = 0, impares = 0;
    lli suma = 0;
    forn(i, n){
        suma += a[i];
        if(a[i] % 2 == 0){
            pares++;
        }
        else
            impares++;

        if(i == 0){
            cout << a[i] << " ";
            continue;
        }
        if(impares%3 == 1){
            cout << suma - impares/3 - 1 << " ";
        }
        else
            cout << suma - impares/3 << " ";
    }
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