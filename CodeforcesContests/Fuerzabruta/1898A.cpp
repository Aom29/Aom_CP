#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long lli;
typedef long double ld;
typedef pair<int, int> p2i;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<p2i> vp2i;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

void solve(){
    int n, k; cin >> n >> k;
    string s;
    cin >> s;
    int conta = 0, contb = 0;
    forn(i, s.size()){
        if(s[i] == 'A'){
            conta++;
        }
        else
            contb++;
    }

    if(contb == k){
        cout << "0\n";
        return;
    }
    if(contb < k){
        int i = 0;
        while(i < s.size() && contb < k){
            if(s[i] == 'A')
                contb++;
            i++;
        }

        cout << "1\n" << i << " B"<< endl;
        return;
    }
    
    int i = 0;
    while(i < s.size() && contb > k){
        if(s[i] == 'B')
            contb--;
        i++;
    }

    cout << "1\n" << i << " A" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}