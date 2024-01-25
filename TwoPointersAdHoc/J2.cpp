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

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

void solve(){
    int n; cin >> n;
    int i = 1, j = n;
    int k1, k2;
    vi ans(n+1);
    while(i < j){
        cout << "? " << i << ' ' << j << endl;
        cout.flush();
        cin >> k1;
        cout << "? " << j << ' ' << i << endl;
        cout.flush();
        cin >> k2;
        if(k2 > k1){
            ans[j] = k2;
            j--;
        }
        else{
            ans[i] = k1;
            i++;
        }
    }

    ans[i] = n;

    cout << "! ";
    forr(k, 1, n)
        cout << ans[k] << ' ';

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}