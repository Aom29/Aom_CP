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
    string s; cin >> s;
    unordered_map <char, int> sig_oc;
    vector<lli> ans(n);
    sig_oc[s[n-1]] = n-1;
    ans[n-1] = 1;

    for(int i = n-2; i >= 0; i--){
        if(sig_oc[s[i]]){
            ans[i] = ans[i+1] + (sig_oc[s[i]] - i);
        }
        else{
            ans[i] = ans[i+1] + (n - i);
        }
        sig_oc[s[i]] = i;
    }

    cout << ans[0] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}