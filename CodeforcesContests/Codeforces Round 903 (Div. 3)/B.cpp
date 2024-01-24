// Olvera Martinez Aaron

#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e9 + 1;

void printvector(vector<int> t){
    for(int i = 0; i < t.size(); i++){
        cout << t[i];
    }
    cout << '\n';
}

int minvector(vector<int> t){
    int minimo = INF;
    for(int i = 0; i < t.size(); i++){
        minimo = min(minimo, t[i]);
    }
    return minimo;
    
}

int maxvector(vector<int> t){
    int imax;
    int maximo = 0;
    for(int i = 0; i < t.size(); i++){
        maximo = max(maximo, t[i]);
        if(maximo <= t[i]){
            maximo = t[i];
            imax = i;
        }
    }
    return imax;
}

bool equalvector(vector<int> t){
    for(int i = 0; i < t.size()-1; i++){
        if(t[i] != t[i+1])  return false;
    }
    return true;
}

void solve(){
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> threads;
    threads.push_back(a);
    threads.push_back(b);
    threads.push_back(c);
    if(equalvector(threads)){
        cout << "YES\n";
        return;
    }

    //printvector(threads);

    for(int i = 0; i < 3; i++){
        int x = minvector(threads);
        int y = maxvector(threads);
        //cout << " y = " << y << '\n';
        threads[y] -= x;
        threads.push_back(x);

        //printvector(threads);

        if(equalvector(threads)){
            cout << "YES\n";
            return;
        }
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