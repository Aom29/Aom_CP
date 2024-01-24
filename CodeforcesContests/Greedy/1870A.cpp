#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

void solve(){
    int n; cin >> n;
    int k, x; cin >> k >> x;
    
    if(n < k || x < k - 1){
        cout << "-1\n";
    }
    else if(k == x){
        cout << (((k-1)*k)/2) + (k-1)*(n-k) << '\n';
    }
    else{
        cout << (((k-1)*k)/2) + x*(n-k) << '\n';
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