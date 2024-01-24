// Olvera Martinez Aaron

#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

void solve(){
    int n, m; cin >> n >> m;
    string x; cin >> x;
    string s; cin >> s;
    int op = 0;
    while(n < m){
        x = x + x;
        op++;
        n = x.size();
    }

    // cout << x << "\n";
    // cout << s << "\n";
    
    for(int i = 0; i < n; i++){
        if(x[i] == s[0]){
            int j = 0;
            while(j < m && x[i + j] == s[j])
                j++;
            if(j == m){
                cout << op << "\n";
                return;
            }
        }
    }

    x = x + x;
    op++;
    n = x.size();

    for(int i = 0; i < n; i++){
        if(x[i] == s[0]){
            int j = 0;
            while(j < m && x[i + j] == s[j])
                j++;
            if(j == m){
                cout << op << "\n";
                return;
            }
        }
    }

    cout << "-1\n";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}