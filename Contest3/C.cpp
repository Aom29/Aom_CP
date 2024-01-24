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
    int q; cin >> q;
    multiset<p2i> m1;
    multiset<p2i> m2;
    int l, r;
    char signo;
    bool par = true;
    while(q--){
        cin >> signo >> l >> r;
        if(par){
            if(signo == '+')
               m1.insert({l,r});
            else
                m1.erase(m1.find({l,r}));

            if(m1.size() < 2){
                cout << "NO\n";
                continue;
            }
            //par = false;
            bool found = false;
            p2i prev_min = *m1.begin();
            m2.insert(prev_min);
            m1.erase(m1.begin());
            while(!m1.empty()){
                p2i curr_min = *m1.begin();
                m2.insert(curr_min);
                m1.erase(m1.begin());
                if(prev_min.se < curr_min.fi){
                    found = true;
                }
                prev_min = curr_min;
            }

            while(!m2.empty()){
                m1.insert(*m2.begin());
                m2.erase(m2.begin());
            }

            if(!found){
                cout << "NO\n";
            }
            else
                cout << "YES\n";
        }
        // else{
        //     if(signo == '+')
        //         m2.insert({l,r});
        //     else
        //         m2.erase(m2.find({l,r}));
        //     if(m2.size() < 2){
        //         cout << "NO\n";
        //         continue;
        //     }
        //     par = true;
        //     bool found = false;
        //     p2i prev_min = *m2.begin();
        //     m1.insert(prev_min);
        //     m2.erase(m2.begin());
        //     while(!m2.empty() && !found){
        //         p2i curr_min = *m2.begin();
        //         m1.insert(curr_min);
        //         m2.erase(m2.begin());
        //         if(prev_min.se >= curr_min.fi){
        //             cout << "YES\n";
        //             found = true;
        //         }
        //         prev_min = curr_min;
        //     }

        //     if(!found){
        //         cout << "NO\n";
        //     }
        // }
        
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}