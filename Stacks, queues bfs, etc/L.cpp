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

char plate[10][10][10];
bool marked[10][10][10];
int k, m, n;
int movesz[6] = {-1, 1, 0, 0, 0, 0};
int movesx[6] = {0, 0, -1, 0, 1, 0};
int movesy[6] = {0, 0, 0, -1, 0, 1};

bool valid(int a, int b, int c){
    return (a>=0 && a<k && b>=0 && b<m && c>=0 && c<n);
}

int bfs(int x, int y){
    queue<pair<int, p2i>> q;
    q.push({k-1, {x, y}});
    int ans = 1;
    marked[k-1][x][y] = true;
    while(!q.empty()){
        int height = q.front().fi;
        int i = q.front().se.fi;
        int j = q.front().se.se;
        q.pop();
        forn(l, 6){
            if(!valid(height+movesz[l], i+movesx[l], j+movesy[l]))
                continue;
            if(!marked[height+movesz[l]][i+movesx[l]][j+movesy[l]] && plate[height+movesz[l]][i+movesx[l]][j+movesy[l]] == '.'){
                ans++;
                q.push({height+movesz[l],{i+movesx[l],j+movesy[l]}});
                marked[height+movesz[l]][i+movesx[l]][j+movesy[l]] = true;
            }
        }
    }
    return ans;
}

void solve(){
    cin >> k >> m >> n;
    int x, y;
    forn(i, k){
        forn(j, m){
            forn(l, n){
                cin >> plate[k-1-i][j][l];
            }
        }
    }

    cin >> x >> y;

    cout << bfs(x-1, y-1) << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}