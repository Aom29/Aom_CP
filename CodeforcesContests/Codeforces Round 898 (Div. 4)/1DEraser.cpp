#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;                           // Par de enteros
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;             // Constantes de tamaño e infinito

void solve(){
    int n, k;
    cin >> n >> k;
    char strip[n];
    int row = 0;
    int op = 0;
    for(int i = 0; i < n; i++)
        cin >> strip[i];
    int i = 0;
    while(i < n){
        if(strip[i] == 'B'){
            i += k;
            op++;
        }
        else{
            i++;
        }
    }
    cout << op << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}