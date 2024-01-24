#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

void solve(){
    int n; cin >> n;
    int even = 0;
    int pair = 0;
    int a;
    for(int i = 0; i < n; ++i){
        cin >> a;
        if(a % 2 == 0)  pair++;
        else    even++;
    }

    if(even % 2 == 0)   cout << "YES";
    else cout << "NO";
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}