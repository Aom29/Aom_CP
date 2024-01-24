#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

void solve(){
    int n; cin >> n;
    int k = INF;
    int d[n], s[n];
    for(int i = 0; i < n; i++)
        cin >> d[i] >> s[i];
    for(int i = 0; i < n; i++){
        k = min(k, d[i] + (s[i]-1)/2);
    }

    cout << k << '\n';


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}