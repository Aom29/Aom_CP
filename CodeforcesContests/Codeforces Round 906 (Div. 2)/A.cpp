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
    int n; cin >> n;
    vi a(n);
    forn(i, n){
        cin >> a[i];
    }
    sort(all(a));
    int b = a[0];
    int c = a[n-1];

    int numb = 0;
    int numc = 0;
    
    forn(i, n){
        if(a[i] == b)
            numb++;
        else if(a[i] == c)
            numc++;
        else{
            cout << "No\n";
            return;
        }
    }

    if(b == c){
        cout << "Yes\n";
    }
    else if((n%2 == 0 && numb == numc) || (n%2 != 0 && abs(numb-numc)==1))
        cout << "Yes\n";
    else
        cout << "No\n";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}