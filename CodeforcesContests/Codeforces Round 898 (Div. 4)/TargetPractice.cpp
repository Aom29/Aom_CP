#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;                           // Par de enteros
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;             // Constantes de tamaño e infinito

void solve(){
    //char target[10][10];
    char target;
    int res = 0;
    int value = 0;
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            //cin >> target[i][j];
            cin >> target;
            if(target == 'X'){
                int mini = min(i,11-i);
                int minj = min(j,11-j);
                value = min(mini,minj);
                res += value;
            }
        }
    }
    cout << res << "\n";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}