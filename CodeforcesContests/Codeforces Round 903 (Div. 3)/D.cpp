// Olvera Martinez Aaron

#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;
int n;

void numDiv(int a, map<int, int> &div){
    int i = 2;
    // Divide entre numeros primos practicamente
    // Ya que los numeros como el 4 se eliminan
    // cuando se divide entre 2, dejando en el
    // mapa solo a los numeros primos.
    while(i*i <= a){
        while(a % i == 0){
            div[i]++;
            a /= i;
        }
        i++;
    }
    // Agregar el ultimo divisor que falta
    // Ej. si i = 5 y a = 5; No entró al while porque 5*5 = 25
    if(a > 1) div[a]++;
}

void solve(){
    cin >> n;
    int a[n];
    map<int, int> div;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        numDiv(a[i], div);
    }

    for(auto d: div){
        if(d.second % n != 0){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}