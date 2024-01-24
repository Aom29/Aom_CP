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
int n, m;

bool valid(int a, int b){
    return (a >= 0 && a < n && b >= 0 && b < m);
}

void solve(){
    cin >> n >> m;
    vector<vector<bool>> marked(n, vector<bool>(m));
    vector<vector<char>> building(n, vector<char>(m));
    forn(i, n)
        forn(j, m){
            cin >> building[i][j];
            if(building[i][j] == '#')
                marked[i][j] = true;
        }

    int ans = 0;
    forn(i, n){
        forn(j, m){
            if(!marked[i][j]){
                //cout << "i = " << i << " , j = " << j << endl;
                ans++;
                //cout << "Ans = " << ans << endl;
                queue<p2i> q;
                marked[i][j] = true;
                q.push({i,j});
                while(!q.empty()){
                    // cout << "AAAAA. i = " << i << " , j = " << j << endl;
                    int curr_i = q.front().fi;
                    int curr_j = q.front().se;
                    //cout << "curr_i = " << curr_i << " , curr_j = " << curr_j << endl;
                    q.pop();
                    if(valid(curr_i-1, curr_j)){
                        if(!marked[curr_i-1][curr_j]){
                            q.push({curr_i-1, curr_j});
                            marked[curr_i-1][curr_j] = true;
                        }
                    }
                    if(valid(curr_i+1, curr_j)){
                        if(!marked[curr_i+1][curr_j]){
                            q.push({curr_i+1, curr_j});
                            marked[curr_i+1][curr_j] = true;
                        }
                    }
                    if(valid(curr_i, curr_j-1)){
                        if(!marked[curr_i][curr_j-1]){
                            q.push({curr_i, curr_j-1});
                            marked[curr_i][curr_j-1] = true;
                        }
                    }
                    if(valid(curr_i, curr_j+1)){
                        if(!marked[curr_i][curr_j+1]){
                            q.push({curr_i, curr_j+1});
                            marked[curr_i][curr_j+1] = true;
                        }
                    }
                }
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