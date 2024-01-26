#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define PI 3.14159265358979323846
 
using namespace std;
 
typedef long long lli;
typedef long double ld;
typedef pair<int, int> p2i;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<p2i> vp2i;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

void solve(){
    double n, R, r; cin >> n >> R >> r;
    double x = (R*sin(PI/n))/(1+sin(PI/n));

    if(n == 1){
        if(r <= R){
            cout << "YES";
            return;
        }
        else{
            cout << "NO";
            return;
        }
    }

    if(n == 2){
        if(2*r <= R){
            cout << "YES";
            return;
        }
        else{
            cout << "NO";
            return;
        }
    }
    // cout << setprecision(30);
    // cout << x + 1e-10 << endl;
    // if (r <= x + 1e-10)
    if(r*(1+sin(PI/n)) <= R*sin(PI/n)+1e-15){
        cout << "YES";
    }

    else
        cout << "NO";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}