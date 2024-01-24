#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

bool repeated(int a, vector<int> &v){
    for(int b: v){
        if(a == b)  return true;
    }
    return false;
}

void solve(){
    int n; cin >> n;
    int a[n];
    vector<int> v;
    int notRepeated = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = n-1; i >= 0; i--){
        if(!repeated(a[i], v)){
            v.push_back(a[i]);
            notRepeated++;
        }
        else{
            break;
        }
    }

    cout << n - notRepeated << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}