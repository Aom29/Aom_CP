// Olvera Martinez Aaron

#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

void solve(){
    int n; cin >> n;
    int a[n][2];
    int i, j;
    int d;
    for(i = 0; i < n; i++){
        cin >> a[i][0] >> d;
        a[i][1] = a[i][0] + d;
    }

    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            if(a[i][0] == a[j][1] && a[j][0] == a[i][1]){
                cout << "YES\n";
                return;
            }

        }
    }
    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

        solve();

    return 0;
}