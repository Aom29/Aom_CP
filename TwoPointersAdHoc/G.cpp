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
    int t; cin >> t;
    lli sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
    string st; cin >> st;
    lli deltaX = ex-sx, deltaY = ey-sy;
    lli n=0, e=0, w=0, s=0;
    bool arriba, derecha;
    if(deltaX < 0){
        w = -deltaX;
        derecha = false;
    }
    else{
        e = deltaX;
        derecha = true;
    }
    if(deltaY < 0){
        s = -deltaY;
        arriba = false;
    }
    else{
        n = deltaY;
        arriba = true;
    }

    int ans = -1;
    lli contX = 0, contY = 0;

    forn(i, t){
        if(st[i] == 'N' && arriba)
            contY++;
        if(st[i] == 'S' && !arriba)
            contY++;
        if(st[i] == 'E' && derecha)
            contX++;
        if(st[i] == 'W' && !derecha)
            contX++;
        if(arriba && n == contY){
            if(derecha && e == contX){
                ans = i+1;
                break;
            }
            if(!derecha && w == contX){
                ans = i+1;
                break;
            }
        }
        if(!arriba && s == contY){
            if(derecha && e == contX){
                ans = i+1;
                break;
            }
            if(!derecha && w == contX){
                ans = i+1;
                break;
            }
        }
    }

    cout << ans;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}