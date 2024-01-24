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
    int q; cin >> q;
    multiset<int> l;
    multiset<int> r;
    // multiset<p2i> m2;
    int left, right;
    char signo;
    while(q--){
        cin >> signo >> left >> right;

        if(signo == '+'){
            l.insert(left);
            r.insert(right);
        }
        else{
            l.erase(l.find(left));
            r.erase(r.find(right));
        }
        
        if(r.empty()){
            cout << "NO\n";
        }
        else if(*r.begin() < *l.rbegin()){
            cout << "YES\n";
        }
        else
            cout << "NO\n";
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