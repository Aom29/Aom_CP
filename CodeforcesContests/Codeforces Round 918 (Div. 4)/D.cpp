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

    unordered_set<char> cons = {'b', 'c', 'd'};
    unordered_set<char> vow = {'a', 'e'};
    cout << s[0] << s[1];
    if(n <= 2){
        cout << endl;
        return;
    }
    int i = 2;
    while(i < n - 1){
        if(vow.count(s[i])){
            cout << s[i];
        }
        else if(cons.count(s[i+1])){
            cout << s[i];
        }
        else
            cout << '.' << s[i];
        i++;
    }

    cout << s[n-1] << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}