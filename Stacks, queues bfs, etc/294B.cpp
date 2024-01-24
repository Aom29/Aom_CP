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
    multiset<int> mst1;
    multiset<int> mst2;

    forn(i, n){
        cin >> a;
        mst1.insert(a);
        mst2.insert(a);
    }

    forn(i, n-1){
        cin >> a;
        mst1.erase(mst1.find(a));
    }

    forn(i, n-2){
        cin >> a;
        mst2.erase(mst2.find(a));
    }

    for(auto it: mst1){
        if(mst2.find(it) != mst2.end()){
            mst2.erase(mst2.find(it));
            break;
        }
    }

    cout << *mst1.begin() << endl;
    cout << *mst2.begin() << endl;
    

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}