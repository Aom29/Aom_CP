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
int m, n;
int movesi[] = {-1, 0, 1, 0};
int movesj[] = {0, -1, 0, 1};

bool valid (int a, int b){
    if(a>=0 && a<m && b>=0 && b<n)
        return true;
    return false;
}

int bfs(p2i start, vector<vector<char>> &mat){

    vector<vector<bool>> marked(m, vector<bool>(n, false));
    queue<pair<int, p2i>> q;
    q.push({0, start});
    marked[start.fi][start.se] = true;
    int fin = 1e7;
    int ans = 0;
    while(!q.empty()){
        int num = q.front().fi;
        int i = q.front().se.fi;
        int j = q.front().se.se;
        q.pop();
        if(num > fin){
            return ans;
        }
        //cout << "i = " << i << ", j = " << j << endl;

        forn(k, 4){
            if(valid(i+movesi[k], j+movesj[k]) && mat[i+movesi[k]][j+movesj[k]] == 'S'){
                fin = num;
            }
            else
            if(valid(i+movesi[k], j+movesj[k]) && (mat[i+movesi[k]][j+movesj[k]] >= '0' && mat[i+movesi[k]][j+movesj[k]] <= '9') && !(marked[i+movesi[k]][j+movesj[k]])){
                marked[i+movesi[k]][j+movesj[k]] = true;
                ans+=mat[i+movesi[k]][j+movesj[k]]-'0';
                q.push({num+1, {i+movesi[k], j+movesj[k]}});
            }
        }
    }
    return ans;
}

void solve(){
    cin >> m >> n;
    vector<vector<char>> mat(m, vector<char>(n));
    p2i me;
    vp2i breeders;
    forn(i, m){
        forn(j,n){
            cin >> mat[i][j];
            if(mat[i][j] == 'E')
                me = {i,j};
        }
    }



    int ans = bfs(me, mat);

    cout << ans;

}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}