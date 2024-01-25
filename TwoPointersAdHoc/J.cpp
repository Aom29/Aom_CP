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
    int i = 1, j = n;
    bool found;
    int imax;
    while(i != j){
        int input;
        cout << "? 1 " << i << ' ' << j << ' ' << n-1 << endl;
        cout.flush();
        cin >> input;
        if(input == n){
            imax = j;
            found = true;
            break;
        }
        else if(input == n-1){
            cout << "? 1 " << j << ' ' << i << ' ' << n-1 << endl;
            cout.flush();
            cin >> input;
                if(input == n){
                imax = i;
                found = true;
                break;
            }
        }
        
        i++; j--;
    }

    if(!found){
        imax = n/2 + 1;
    }

    vi a(n+1);
    int input;
    forr(i, 1, n){
        if(i == imax){
            a[i] = n;
        }
        else{
            cout << "? 2 " << i << ' ' << imax << ' ' << 1 << endl;
            cout.flush();
            cin >> input;
            a[i] = input;
        }
    }

    cout << "! ";
    forr(i, 1, n)
        cout << a[i] << ' ';

    cout << endl;
    cout.flush();

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}