#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

void solve(){
    int x, y, n; cin >> x >> y >> n;
    int a[n];
    a[n-1] = y;
    int k = 1; 
    for(int i = n-2; i > 0; i--){
        a[i] = a[i+1] - k;
        k++;
    }
    if(a[1] - k < x){
        cout << "-1\n";
    }   
    else{
        a[0] = x;
        for(int i = 0; i < n; i++){
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}