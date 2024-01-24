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

void rec(string s, int &ans, unordered_map<string, bool> & memo){
    if(memo[s]){
        return;
    }
    // cout << "S = " << s<< endl;
    ans++;
    memo[s] = true;

    if(s.size() == 2){
        if(s[0] == s[1]  && !memo[string(s[0], 1)]){
            ans++;
            memo[string(s[0], 1)] = true;
        }
        else{
            if(!memo[string(s[0], 1)]){
                ans++;
                memo[string(s[0], 1)] = true;
            }
            if(!memo[string(s[1], 1)]){
                ans++;
                memo[string(s[1], 1)] = true;
            }
        }
        return;
    }

    if(s[0] == s[1]){
        //cout << "new = " << s.substr(1) << endl;
        rec(s.substr(1), ans, memo);
        return;
    }

    string aux1 = s.substr(1);
    string aux2 = s[0] + s.substr(2);

    // cout << "aux1 = " << aux1 << endl;
    // cout << "aux2 = " << aux2 << endl;

    rec(aux1, ans, memo);
    rec(aux2, ans, memo);
    
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    unordered_map <string, bool> memo;
    if(n == 1){
        cout << "1" << endl;
        return;
    }
    rec(s, ans, memo);

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