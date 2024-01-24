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
int n, k;
vi a(55);
unordered_set<lli> printed;

void explore(int length, int inicio, lli sum, vi &psum){
    if(k == 0)  return;
    if (length == 0){
        if(printed.find(sum) == printed.end()){
            cout << psum.size() << " ";
            forn(i, psum.size()){
                cout << psum[i] << " ";
            }
            cout << endl;
            printed.insert(sum);
            k--;
        }
        return;
    }
    if(inicio >= n) return;

    for(int i = inicio; i >= 0; i--){
        psum.push_back(a[i]);
        explore(length-1, i-1, sum + a[i], psum);
        psum.pop_back();
    }
}

void solve(){
    cin >> n >> k;
    forn(i,n)
        cin >> a[i];
    sort(a.begin(), a.begin() + n);
    int length;
    vi psum;
    for(length = 1; length <= n; length++){
        lli sum = 0;
        for(int i = n-1; i >= 0; i--){
            psum.push_back(a[i]);
            explore(length-1, i-1, sum + a[i], psum);
            psum.pop_back();
        }
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