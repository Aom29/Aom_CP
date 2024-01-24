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
    int left;
    int right;
    int total = 0;
    int Ms = 0;
    string s; cin >> s;

    for(char c: s){
        if(c == 'T')
            total++;
        if(c == 'M')
            Ms++;
    }

    if(2*Ms != total){
        cout << "NO\n";
        return;
    }


    Ms = 0;
    left = 0;
    right = total;

    for(char c: s){
        if(c == 'T'){
            left++;
            right--;
        }
        if(c == 'M'){
            Ms++;
            left--;
            if(left < 0){
                cout << "NO\n";
                return;
            }
        }
    }

    if(left != Ms){
        cout << "NO\n";
                return;
    }

    Ms = 0;
    right = 0;
    left = total;

    for(int i = n-1; i >= 0; i--){
        char c = s[i];
        if(c == 'T'){
            right++;
            left--;
        }
        if(c == 'M'){
            Ms++;
            right--;
            if(right < 0){
                cout << "NO\n";
                return;
            }
        }
    }

    if(right != Ms){
        cout << "NO\n";
                return;
    }

    cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}