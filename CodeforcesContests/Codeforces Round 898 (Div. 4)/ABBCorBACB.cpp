#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;                           // Par de enteros
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;             // Constantes de tamaño e infinito

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> As;
    bool totalA = false;
    if(s[0] == 'B' || s[n-1] == 'B'){
        totalA = true;
    }

    for(int i = 0; i < n - 1; i++){
        if(s[i] == 'B' && s[i] == s[i+1]){
            totalA = true;
        }
    }

    int partial_as = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A'){
            partial_as++;
        }
        else{
            if(partial_as > 0){
                As.push_back(partial_as);
                partial_as = 0;
            }
        }
    }

    if(partial_as > 0){
        As.push_back(partial_as);
    }

    sort(As.begin(),As.end());

    int ans = 0;

    if(As.size() == 0){
        cout << "0\n";
        return;
    }

    if(totalA)
        ans = As[0];
    for(int i = 1; i < As.size(); i++){
        ans += As[i];
    }

    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}