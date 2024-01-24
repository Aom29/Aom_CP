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

bool valid(int m, vi &h){
    int aux1 = 0, aux2 = 0;
    int inc;
    for(int i = h.size()-1; i > 1; i--){
        // cout << "m = " << m << ", i = " << i << ", h[i] = " << h[i] << ", aux1 = " << aux1 << endl;
        if(m > h[i]+aux1){
            // cout << "A\n";
            return false;
        }
        if(aux1 - m >= 0){
            inc = h[i]/3;
        }
        else{
            inc = (h[i]+aux1-m)/3;
        }

        aux1 = inc+aux2;
        aux2 = 2*inc;
    }

    if(h[1]+aux1 < m || h[0]+aux2 < m)
        return false;

    return true;
}

void solve(){
    int n; cin >> n;
    vi h(n);
    int maxih = 0;
    forn(i,n){
        cin >> h[i];
        maxih = max(maxih, h[i]);
    }


    int l = 1, r = maxih;
    while(l<=r){
        int m = (l+r)/2;
        if(!valid(m, h)){
            r = m-1;
        }
        else{
            l = m+1;
        }
    }

    cout << l-1 << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}