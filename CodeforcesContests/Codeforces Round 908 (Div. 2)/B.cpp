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
    unordered_map<int, int> appears;
    unordered_map<int, int> cont;
    vi a(n);
    int num2 = 0;
    bool posible = true;
    forn(i, n){
        cin >> a[i];
        appears[a[i]]++;
        // if(appears[a[i]] > 3){
        //     posible = false;
        // }
        if(appears[a[i]] == 2)
            num2++;
    }

    if(!posible || num2 < 2){
        cout << "-1" << endl;
        return;
    }
    vi b(n);
    bool first = false;
    forn(i, n){
        cont[a[i]]++;
        if(cont[a[i]] == 1)
            b[i] = 1;
        else if(cont[a[i]] == 2 && !first){
            b[i] = 2;
            first = true;
        }
        else if(cont[a[i]] == 2){
            b[i] = 3;
        }
        else
            b[i] = 1;
    }

    forn(i, n)
        cout << b[i] << " ";
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--){
        solve();

    }

    return 0;
}