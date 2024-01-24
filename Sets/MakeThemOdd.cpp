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

int divisionsByTwo(int a, unordered_map<int, int> &mp){
    int cont = 0;
    while(a%2 == 0){
        mp[a]++;
        cont ++;
        a = a/2;
    }

    return cont;
}

bool compare(int a, int b){
    return a > b;
}

void solve(){
    int n; cin >> n;
    vi a(n);
    int ans = 0;
    unordered_map<int, int> mp;
    forn(i, n){
        cin >> a[i];
    }

    sort(all(a), compare);

    forn(i, n){
        if(mp[a[i]] == 0){
            ans += divisionsByTwo(a[i], mp);
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