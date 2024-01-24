#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

void solve(){
    string s; cin >> s;
    int k = 0, form = 1, ac = 1;
    int rep = 1;
    int fact = 1;
    for(int i = 1; i < s.length(); i++){
        ac = 1;
        while(i < s.length() && s[i] == s[i-1]){
            k++;
            ac++;
            i++;
        }
        rep = (rep * 1LL * ac) % 998244353;
    }
    form = rep;
    for(int i = 1; i <= k; i++){
        form = (form * 1LL * i) % 998244353;
    }

    cout << k << ' ' << form << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}