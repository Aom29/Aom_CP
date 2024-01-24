#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

void solve(){
    string s; cin >> s;
    int upper = 0, lower = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            lower++;
        }
        else
            upper++;
    }

    if(lower >= upper){
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= 'a' && s[i] <= 'z')
                continue;
            else{
                s[i] = s[i] + ('a'-'A'); 
            }
        }
    }
    else{
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - ('a' - 'A');
        }
    }

    cout << s;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //int t; cin >> t;

    //while(t--)
        solve();

    return 0;
}