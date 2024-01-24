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

const int SIZE = 1e5 + 5,INF = 1e8 + 5;
char w[2][SIZE];
bool marked[2][SIZE];
int n, k;

bool valid(int a, int b){
    return (a >= 0 && a < 2 && b >= 0 && b < n);
}

bool bfs(){
    int movesx[] = {1, -1, 0, 0};
    int movesy[] = {k, k, 1, -1};
    queue<pair<int, p2i>> q;
    if(!marked[0][0]){
        q.push({0, {0,0}});
        marked[0][0] = true;
    }

    while(!q.empty()){
        int water = q.front().fi;
        int i = q.front().se.fi;
        int j = q.front().se.se;
        q.pop();

        if(water > j){
            continue;
        }

        if(j >= n && water <= j){
            return true;
        }

        forn(l, 4){
            if(!valid(i+movesx[l],j+movesy[l])){
                if(j+movesy[l] >= n){
                    return true;
                }
                continue;
            }

            if(!marked[i+movesx[l]][j+movesy[l]]){
                marked[i+movesx[l]][j+movesy[l]] = true;
                q.push({water+1, {i+movesx[l], j+movesy[l]}});
            }
        }

    }

    return false;

}

void solve(){
    cin >> n >> k;
    forn(i, n){
        cin >> w[0][i];
        if(w[0][i] == 'X')
            marked[0][i] = true;
    }
    forn(i, n){
        cin >> w[1][i];
        if(w[1][i] == 'X')
            marked[1][i] = true;
    }

    if(bfs())
        cout << "YES";
    else
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