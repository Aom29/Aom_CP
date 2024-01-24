// Olvera Martinez Aaron

#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

char max4(char a, char b, char c, char d){
    if(a > b && a > c && a > d)
        return a;
    if(b > c && b > d)
        return b;
    if(c > d)
        return c;
    return d;
}

int totalop(char a, char b, char c, char d){
    int op = 0;
    int maximo = max4(a, b, c, d);
    // cout << "maximo = " << maximo << "\n";
    // cout << "a = " << (int)a << " b = " << (int)b << " c = " << (int)c << " d = " << (int)d << "\n";
    op += maximo - a;
    op += maximo - b;
    op += maximo - c;
    op += maximo - d;
    // cout << "op = " << op << "\n";
    return op;
}

void solve(){
    int n; cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> v[i][j];
    int mid = n / 2;
    int op = 0;
    for(int i = 0; i < mid; i++){
        for(int j = 0; j < mid; j++){
            op += totalop(v[i][j], v[j][n-1-i], v[n-1-i][n-1-j], v[n-1-j][i]);
        }
    }

    cout << op << "\n";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--){
        //cout << "t = " << t << "\n";
        solve();

    }

    return 0;
}