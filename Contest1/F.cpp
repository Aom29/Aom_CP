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
    int a;
    int k;
    map<int, int> unionn;
    set<int> sets[50];
    forn(i, n){
        cin >> k;
        forn(j, k){
            cin >> a;
            sets[i].insert(a);
            unionn[a]++;
        }
    }

    int cont = 0;
    for(auto it: unionn){
        cont++;
    }

    int ans = 0;
    for(auto it: unionn){
        // cout << it.fi << ": ";
        set<int> pos_ans;
        forn(i, n){
            if(sets[i].find(it.fi) == sets[i].end()){
                for(auto num: sets[i]){
                    pos_ans.insert(num);
                }
            }
        }
        // cout << pos_ans.size() << endl;
        if(pos_ans.size() < cont){
            ans = max((int)pos_ans.size(), ans);
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