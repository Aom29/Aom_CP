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
    int n, k; cin >> n >> k;
    int a;
    lli cont = 1;
    vi finalans;
    forn(i, n){
        cin >> a;
        cont *= a;
    }


    if(2023 % cont != 0 || cont > 2023){
        cout << "NO\n";
        return;
    }
    

    if(cont == 289){
        finalans.pb(7);
    }
    if(cont == 119){
        finalans.pb(17);
    }

    if(cont == 17){
        finalans.pb(119);
    }
    if(cont == 7){
        finalans.pb(289);
    }

    if(cont == 1){
        finalans.pb(2023);
    }
        
    int tam = finalans.size();
    forn(i, k-tam)
            finalans.pb(1);

    if(finalans.size() == k){
        cout << "YES\n";
        for(lli i: finalans){
            cout << i << " ";
        }
        cout << endl;
    }
    else
        cout << "NO\n";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}