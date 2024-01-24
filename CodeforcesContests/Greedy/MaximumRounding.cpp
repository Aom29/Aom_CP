#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

void solve(){
    string x;  cin >> x;
    char c = '0';

    for(int i = x.size()-1; i > 0; i--){
        if(x[i] >= '5')  x[i-1]++;
    }
    
    if(x[0] >= '5')  c = '1';
    
    if(c == '1'){
        cout << '1';
        for(int i = 0; i < x.size(); i++)
            cout << '0';
    }
    else{
        bool maxi = false;
        for(int i = 0; i < x.size(); i++){
            if(maxi)   cout << '0';
            else{
                if(x[i] < '5')    cout << x[i];
                else{
                    cout << '0';
                    maxi = true;
                }
            }
                
        }      
    }
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