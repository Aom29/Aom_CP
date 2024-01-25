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
char m[4][4];
int moves[] = {-1, 1};

bool sameColor(char a, char b, char c){
    return (a == b && b == c);
}

bool inm(int a, int b){
    return (a >= 0 && b >= 0 && a < 4 && b < 4);
}

bool pass(int a, int b){
    
    forn(i, 2){
        forn(j, 2){
            if(inm(a+moves[i], b+moves[j]) && sameColor(m[a+moves[i]][b], m[a][b+moves[j]], m[a+moves[i]][b+moves[j]])){
                return true;
            }
        }
    }
    return false;
}

void solve(){
    forn(i, 4)
        forn(j, 4)
            cin >> m[i][j];
    
    forn(i, 4)
        forn(j, 4){
            if(pass(i, j)){
                cout << "YES";
                return;
            }
        }
    cout << "NO";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}