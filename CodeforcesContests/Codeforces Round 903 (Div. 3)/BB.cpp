// Olvera Martinez Aaron

#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

int min3(int a, int b, int c){
    return min(a, min(b, c));
}

int max3(int a, int b, int c){
    if (a > b && a > c)
        return 1;
    if (b > c)
        return 2;
    return 3;
}

bool equal3(int a, int b, int c){
    return a == b && b == c;
}

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int minimoooo = min3(a, b, c);
    if(a%minimoooo==0 && b%minimoooo==0 && c%minimoooo==0){
        if(equal3(a, b, c)){
            cout << "YES\n";
            return;
        }
        
        for(int i = 0; i < 3; i++){
            int x = min3(a, b, c);
            int y = max3(a, b, c);

            if(y == 1){
                a -= x;
            }
            else if(y == 2){
                b -= x;
            }
            else{
                c -= x;
            }
            //cout << a << " " << b << " " << c << "\n";
            if(equal3(a, b, c)){
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n"; return;
    }

    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}