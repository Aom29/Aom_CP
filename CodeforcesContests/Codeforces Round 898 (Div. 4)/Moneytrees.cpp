#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;                           // Par de enteros
using lli = long long int;

const int SIZE = 2e5 + 5,INF = 1e8 + 1;             // Constantes de tamaño e infinito
int n, k;
int prefix[SIZE], a[SIZE], h[SIZE], length[SIZE];

bool valid_segments(int longitud){
    for(int i = 0; i < n - longitud + 1; i++){
        if(length[i] >= longitud){
            int sum = prefix[i+longitud] - prefix[i];
            if(sum <= k)
                return true;
        }
    }
    return false;
}

void solve(){
    cin >> n >> k;
    prefix[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        prefix[i+1] = prefix[i] + a[i];
    }

    for(int i = 0; i < n; i++)
        cin >> h[i];

    length[n-1] = 1;

    for(int i = n-2; i >= 0; i--){
        if(h[i] % h[i+1] == 0){
            length[i] = length[i+1] + 1;
        }
        else
            length[i] = 1;
    }

    int l = 1, r = SIZE;
    while(l <= r){
        int m = (l+r)/2;
        if(valid_segments(m)){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    cout << r << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}