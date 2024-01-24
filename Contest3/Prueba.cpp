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
    
    multiset<p2i> m1;
    multiset<p2i> m2;
    int l, r;
    bool par = true;
    char signo;
    while(q--){
        cin >> signo >> l >> r;
        if(signo == '+')
            m1.insert({l,r});
        else
            m1.erase(m1.find({l,r}));
    }



    while(!m1.empty()){
        cout << (*(m1.begin())).fi << (*(m1.begin())).se << endl;
        m1.erase(m1.find({(*(m1.begin())).fi, (*(m1.begin())).se}));
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