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

bool compare(string a, string b){
    return a.size() < b.size();
}

void solve(){
    int n; cin >> n;
    // fi: length, se.fi: sum, se.se: nStrings.
    unordered_map<int, unordered_map<int, int>> str;
    int sp1[6];
    int sp2[6];
    lli ans = 0;
    vector<string> s(n);
    forn(i, n)
        cin >> s[i];
    sort(all(s), compare);

    for(string aux: s){
        forn(i, 6){
            sp1[i] = 0;
            sp2[i] = 0;
        }
        cin >> aux;
        int hi = aux.size();
        ans++;
        forn(i, aux.size()){
            sp1[i+1] = sp1[i] + (aux[i] - '0');
        }
        for(int j = aux.size()-1; j >= 0; j--){
            sp2[j] = sp2[j+1] + (aux[j] - '0');
        }

        
        int iaux = 0;
        for(int i = 0; i < hi; i+=2, iaux++){
            ans += str[hi-i][sp2[iaux]-sp1[iaux]];
        }

        int jaux = 0;
        for(int j = hi; j > 0; j-=2, jaux++){
            ans += str[j][sp1[hi-jaux]-sp2[hi-jaux]];
        }

        str[hi][sp1[hi]]++;
    }
    
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}