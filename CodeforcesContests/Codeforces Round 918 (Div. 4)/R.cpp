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
    lli a;
    unordered_set<lli> sums;
    lli aceven = 0;
    lli acodd = 0;
    lli ac = 0;
    sums.insert(0);
    bool ans = false;
    forn(i, n){
        cin >> a;
        if((i+1) % 2 != 0){
            acodd += a;
            ac = acodd-aceven;
            // cout << "ac = " << ac << endl;
            if(sums.count(ac) && !ans){
                ans = true;
            }
            else if(!ans)
                sums.insert(ac);
        }
        else{
            aceven += a;
            ac = acodd-aceven;
            // cout << "ac = " << ac << endl;
            if(sums.count(ac) && !ans){
                ans = true;
            }
            else if(!ans)
                sums.insert(ac);
        }
    }
    if(n == 1 || !ans){
        cout << "NO\n";
    }
    else
        cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}