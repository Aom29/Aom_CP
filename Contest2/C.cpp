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
    string s; cin >> s;
    string ans = "";
    char c = 'a';
    int i = 0;
    bool alista = false;
    while(i < s.size()){
        if(!alista){
            if(s[i] <= c){
                s[i] = c;
                c++;
                alista = true;
            }
            i++;
        }
        else{
            if(s[i] <= c || s[i] <= c-1){
                s[i] = c;
                c++;
            }
            i++;
        }
        if(c > 'z')   break;
    }

    if(c > 'z'){
            cout << s;
            return;
        }
    cout << "-1";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}