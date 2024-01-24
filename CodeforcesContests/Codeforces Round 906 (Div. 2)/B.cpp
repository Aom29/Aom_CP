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
    int n, m; cin >> n >> m;
    string s, t;
    cin >> s;
    cin >> t;
    bool sgood = true;
    forn(i,n-1){
        if(sgood && s[i] == s[i+1]){
            sgood = false;
            break;
        }
    }

    if(sgood){
        cout << "Yes\n";
        return;
    }

    bool tgood = true;

    if(t[0] != t[m-1]) tgood = false;

    forn(i,m-1){
        if(tgood && t[i] == t[i+1]){
            tgood = false;
            break;
        }
    }

    if(!tgood){
        cout << "No\n";
        return;
    }

    bool b0 = false;
    bool b1 = false;

    forn(i, n-1){
        if(s[i] == s[i+1]){
            if(s[i] == '0'){
                b0 = true;
            }
            else{
                b1 = true;
            }
        }
    }
    
    if(b0 && b1){
        cout << "No\n";
        return;
    }

    if(b0 && t[0] == '1'){
        cout << "Yes\n";
        return;
    }
    else if(b1 && t[0] == '0'){
        cout << "Yes\n";
        return;
    }
    else{
        cout << "No\n";
        return;
    }


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}