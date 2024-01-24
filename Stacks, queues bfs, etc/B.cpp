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

const int SIZE = 1e5 + 1,INF = 1e8;


void solve(){
    int n; cin >> n;
    char grid[n][n];
    int minimo[n][n];
    int startX, startY, goalX, goalY;
    priority_queue<pair<int, pair<char, p2i>>, vector<pair<int, pair<char, p2i>>>, greater<pair<int, pair<char, p2i>>>> q;
    bool marked[n][n];
    
    forn(i, n)
        forn(j, n){
            cin >> grid[i][j];
            minimo[i][j] = INF;
            marked[i][j] = false;
        }
    
    cin >> startX >> startY >> goalX >> goalY;

    if(startX == goalX && startY == goalY){
        cout << "0";
        return;
    }

    minimo[startX][startY] = 0;
    marked[startX][startY] = true;
    q.push({1, {'H', {startX, startY}}});
    q.push({1, {'V', {startX, startY}}});

    while(!q.empty()){

        int current_i = q.top().se.se.fi;
        int current_j = q.top().se.se.se;
        int moves = q.top().fi;
        char movement = q.top().se.fi;
        q.pop();

        if(!marked[current_i][current_j]){
            minimo[current_i][current_j] = moves;
            marked[current_i][current_j] = true;
        }


        cout << moves << " " << current_i << " " << current_j << endl;

        if(movement == 'V'){ 
            // Movimiento vertical arriba (añade celdas horizontales adyacentes)
            for(int i = current_i - 1; i >= 0; i--){
                if(grid[i][current_j] == 'X')
                    break;
                if(!marked[i][current_j]){
                // Se van llenando 
                    minimo[i][current_j] = moves;
                    marked[i][current_j] = true;

                    // Adyacente izquierda
                    if(current_j - 1 >= 0 && !marked[i][current_j-1] && grid[i][current_j-1] != 'X'){
                        q.push({moves+1, {'H', {i, current_j - 1}}});
                    }
                    // Adyacente derecha
                    if(current_j + 1 < n && !marked[i][current_j+1] && grid[i][current_j+1] != 'X'){
                        q.push({moves+1, {'H', {i, current_j+1}}});
                    }

                }
            }
            
            // Movimiento vertical abajo (añade celdas horizontales adyacentes)
            for(int i = current_i+1; i < n; i++){
                if(grid[i][current_j] == 'X')
                    break;
                if(!marked[i][current_j]){
                // Se van llenando 
                    minimo[i][current_j] = moves;
                    marked[i][current_j] = true;

                    // Adyacente izquierda
                    if(current_j - 1 >= 0 && !marked[i][current_j-1] && grid[i][current_j-1] != 'X'){
                        q.push({moves+1, {'H', {i, current_j - 1}}});
                    }
                    // Adyacente derecha
                    if(current_j + 1 < n && !marked[i][current_j+1] && grid[i][current_j+1] != 'X'){
                        q.push({moves+1, {'H', {i, current_j+1}}});
                    }

                }
            }
        }

        else{
            // Movimiento horizontal atrás
            for(int j = current_j - 1; j >= 0; j--){
                if(grid[current_i][j] == 'X')
                    break;
                if(!marked[current_i][j]){
                // Se van llenando 
                    minimo[current_i][j] = moves;
                    marked[current_i][j] = true;

                    // Adyacente arriba
                    if(current_i - 1 >= 0 && !marked[current_i-1][j] && grid[current_i-1][j] != 'X'){
                        q.push({moves+1, {'V', {current_i-1, j}}});
                    }
                    // Adyacente abajo
                    if(current_i + 1 < n && !marked[current_i+1][j] && grid[current_i+1][j] != 'X'){
                        q.push({moves+1, {'V', {current_i+1, j}}});
                    }
                }

            }

            // Movimiento horizontal atrás
            for(int j = current_j + 1; j < n; j++){
                if(grid[current_i][j] == 'X')
                    break;
                if(!marked[current_i][j]){
                // Se van llenando 
                    minimo[current_i][j] = moves;
                    marked[current_i][j] = true;

                    // Adyacente arriba
                    if(current_i - 1 >= 0 && !marked[current_i-1][j] && grid[current_i-1][j] != 'X'){
                        q.push({moves+1, {'V', {current_i-1, j}}});
                    }
                    // Adyacente abajo
                    if(current_i + 1 < n && !marked[current_i+1][j] && grid[current_i+1][j] != 'X'){
                        q.push({moves+1, {'V', {current_i+1, j}}});
                    }
                }
            }
        }

            forn(i, n){
                forn(j, n){
                    if(grid[i][j] == 'X'){
                        cout << 'X' << " ";
                    }
                    else if(i == goalX && j == goalY)
                        cout << 'G' << " ";
                    else if(i == startX && j == startY)
                        cout << 'S' << " ";
                    else if(minimo[i][j] == INF){
                        cout << '.' << " ";
                    }
                    else
                        cout << minimo[i][j] << " ";
                }
                cout << endl;
            }
            
            cout << endl; 

        // Verificamos si ya se llegó a la meta
        if(marked[goalX][goalY]){
            forn(i, n){
                forn(j, n){
                    if(grid[i][j] == 'X'){
                        cout << 'X' << " ";
                    }
                    else if(i == goalX && j == goalY)
                        cout << 'G' << " ";
                    else if(i == startX && j == startY)
                        cout << 'S' << " ";
                    else if(minimo[i][j] == INF){
                        cout << '.' << " ";
                    }
                    else
                        cout << minimo[i][j] << " ";
                }
                cout << endl;
            }
            
            cout << endl; 
            
            cout << minimo[goalX][goalY];
            return;
        }

    }

    

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}