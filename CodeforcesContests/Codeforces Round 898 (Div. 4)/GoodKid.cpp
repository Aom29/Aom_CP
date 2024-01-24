#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;                           // Par de enteros
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;             // Constantes de tamaño e infinito

void solve(){
    int n; cin >> n;
    int a[n];
    int min = INF;
    int prod = 1;
    int ceros = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0)
            ceros++;;
        if(a[i] < min)
            min = a[i];
    }
    if(ceros == 1) {
        for(int i = 0; i < n; i++){
            if(a[i] != 0)
                prod *= a[i];
        }
    }
    else if(ceros > 1) prod = 0;
    else {
        for(int i = 0; i < n; i++){
            prod *= a[i];
        }
        prod = (min+1)*(prod/min);
    }

    cout << prod << "\n";
        
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}