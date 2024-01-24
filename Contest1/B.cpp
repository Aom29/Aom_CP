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
lli n;

bool valid(lli x){

    lli x2 = x*x;
    lli maxarr = 0, minarr = 0;
    for(lli i = 0; i < n-1; i++){
        maxarr += (x+1-i);
    }

    maxarr++;

    for(lli i = 1; i <= n-1; i++){
        minarr += i;
    }

    minarr += x+1;

    if(abs(maxarr-minarr) < n)
        return false;


    lli li = x2 - maxarr;
    lli cont = n - li%n;
    lli ocont = cont;

    vector<lli> ans(n);
    for(lli i = 0; i < n - 1; i++){
        ans[n-1-i] = x+1 - i;
    }

    ans[0] = 1;

    lli i = 1;
    while(cont > 0){
        if(ans[i] - cont >=  ans[i-1] + 1){
            ans[i] -= cont;
            break;
        }
        else{
            cont -= (ans[i] - ans[i-1] - 1);
            ans[i] = ans[i-1]+1;
            i++;
        }
    }

    lli suma = (li + ocont) / n;
    lli ressuma = 0;

    for(lli i = 0; i < n; i++){
        cout << ans[i] + suma << " ";
        ressuma += (ans[i] + suma);
    }

    cout << endl;

    //cout << endl << "Suma = " << ressuma <<  ", X2 = " << (ans[n-1] - ans[0])*(ans[n-1] - ans[0]) << ", X2O = " << x2 << endl;

    return true;

}

void solve(){
    cin >> n;

    if(n == 2){
        cout << "1 3\n";
        return;
    }

    lli l = n+1, r = 3e5+1;
    
    if(n < 1e3+1) r = 1e3+1;

    while(l <= r){
        lli m = (l+r)/2;
        if(!valid(m))
            l = m+1;
        else{
            break;
        }
    }
    

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}