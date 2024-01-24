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

bool iswallfinished(lli height, vector<lli> &a, int n){
    forn(i,n-1){
        if(a[i] != a[i+1]){
            return false;
        }
    }

    return true;
}

void printA(vector<lli> &a, int n){
    forn(i, n)
        cout << a[i] << ' ';
    cout << endl;
}

void solve(){
    int n; cin >> n;
    vector<lli> a(n);
    lli maxa = 0;
    forn(i, n){
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }

    // Greedy
    forn(i, n){
        if(a[i] < maxa-2){
            if((maxa - a[i]) % 2 == 0){
                a[i] = maxa - 2;
            }
            else
                a[i] = maxa - 1;
        }
    }

    // printA(a, n);
    // maxa-2
    forn(i,n-1){
        if(a[i] == a[i+1] && a[i] == maxa-2){
            a[i]++;
            a[i+1]++;
        }
        else if(a[i] == maxa-2)
            a[i]+=2;
    }

    if(a[n-1] == maxa-2)
            a[n-1]+=2;    

    // printA(a, n);
    // maxa-1
    forn(i,n-1){
        if(a[i] == a[i+1] && a[i] == maxa-1){
            a[i]++;
            a[i+1]++;
        }
        else if(a[i] == maxa-1)
            a[i]+=2;
    }

    if(a[n-1] == maxa-1)
            a[n-1]+=2;   

    // printA(a, n);
    if(iswallfinished(maxa, a, n)){
        cout << "YES";
        return;
    }

    // maxa
    forn(i,n-1){
        if(a[i] == a[i+1] && a[i] == maxa){
            a[i]++;
            a[i+1]++;
        }
        else if(a[i] == maxa)
            a[i]+=2;
    }

    if(a[n-1] == maxa)
            a[n-1]+=2;   

    // printA(a, n);
    if(iswallfinished(maxa+1, a, n)){
        cout << "YES";
        return;
    }

    // maxa + 1
    forn(i,n-1){
        if(a[i] == a[i+1] && a[i] == maxa+1){
            a[i]++;
            a[i+1]++;
        }
        else if(a[i] == maxa+1)
            a[i]+=2;
    }

    if(a[n-1] == maxa+1)
            a[n-1]+=2;   

    // printA(a, n);
    if(iswallfinished(maxa+2, a, n)){
        cout << "YES";
        return;
    }

    // fin, solo horizontales
    forn(i,n-1){
        if(a[i] == a[i+1] && a[i] == maxa + 2){
            a[i]++;
            a[i+1]++;
        }
    }

    // printA(a, n);
    if(iswallfinished(maxa+3, a, n)){
        cout << "YES";
        return;
    }

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