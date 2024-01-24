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
    unordered_map<char, int> mapa;
    int pares = 0, impares = 0;
    for(char c: s)
        mapa[c]++;
    for(auto it: mapa){
        if(it.se%2 == 0){
            pares++;
        }
        else
            impares++;
    }

    bool first = true;

    if(impares == 0){
        cout << "First";
        return;
    }
        
    while(impares!=1){
        if(pares > 0){
            pares--;
            impares++;
        }
        else
            impares--;
        first = !first;
    }


    if(first)
        cout << "First";
    else
        cout << "Second";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}