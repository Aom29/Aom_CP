#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e9 + 1;

void solve(){
    int n;  cin >> n;
    int a[n], b[n];
    lli suma = 0, sumb = 0;
    int mina = INF, minb = INF;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mina = min(mina, a[i]);
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        minb = min(minb, b[i]);
    }
    for(int i = 0; i < n; i++){
        suma += mina + b[i];
        sumb += minb + a[i];
    }

    cout << min(suma, sumb) << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}