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

bool valid(lli k, lli n){
    lli takes = 0;
    int i = 1;
    lli contvas = k;
    n-=k;
    while(n > 0){
        takes += n/10;
        n-=n/10;
        if(n >= k){
            contvas += k;
            n-=k;
        }
        else{
            contvas+=n;
            n = 0;
        }
    }
    return contvas >= takes;
}

void solve(){
    lli n; cin >> n;
    lli l = 1, r = n;
    while(l <= r){
        lli mid = (l+r)/2;
        if(valid(mid, n)){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }

    cout << r+1;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}