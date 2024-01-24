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

void solve(){
    cin >> n >> k;
    forn(i,n)
        cin >> a[i];
    sort(a.begin(), a.begin() + n);
    int add;
    vi psum;
    lli sum;
    for(sum = 0, add = 0; add < n; add++){
        forn(i, add){
            psum.push_back(a[n-1-i]);
            sum += a[n - 1 - i];
        }
        for(int j = n - 1 - add; j >= 0 && k; j--){
            cout << add + 1 << " ";
            forn(i, add)
                cout << psum[i] << " ";
            cout << a[j];
            cout << endl;
            k--;
        }
        psum.clear();
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