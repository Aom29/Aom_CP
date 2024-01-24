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
    int n, m; cin >> n >> m;
    vi ad[n+1];
    int a, b;
    vector<bool> marked(n+1, false);
    vector<tuple<int, int, int>> ans;
    forn(i, m){
        cin >> a >> b;
        ad[a].push_back(b);
        ad[b].push_back(a);
    }

    forr(i, 1, n){
        if(ad[i].size() <= 1) continue;
        if(ad[i].size() >= 3){
            cout << "-1";
            return;
        }
        else{
            if(ad[ad[i][0]].size() >= 3 || ad[ad[i][1]].size() >= 3){
                cout << "-1";
                return;
            }
            else if(ad[ad[i][0]].size() == 1 && ad[ad[i][1]].size() == 3){
                continue;
            }
            else{
                bool cont = false;
                for(int ent: ad[ad[i][0]]){
                    if(ent == ad[i][1])
                        cont = true;
                }
                if(!cont){
                    cout << "-1";
                    return;
                }
            }
        }
    }

    forr(i, 1, n){
        if(ad[i].size() == 2 && !marked[i]){
            ans.push_back({i, ad[i][0], ad[i][1]});
            marked[i] = true;
            marked[ad[i][0]] = true;
            marked[ad[i][1]] = true;
        }
    }

    int cont = 0;
    vi remaining;
    int missing = 0;

    forr(i, 1, n){
        if(!marked[i] && ad[i].size() == 0){
            remaining.push_back(i);
            marked[i] = true;
        }
        if(!marked[i] && ad[i].size() == 1){
            missing++;
        }
    }

    forr(i, 1, n){
        
        if(!marked[i] && ad[i].size() == 1){
            if(remaining.empty()){
                cout << "-1";
                return;
            }
            marked[i] = true;
            marked[ad[i][0]] = true;
            ans.push_back({i, ad[i][0], remaining.back()});
            remaining.pop_back();
        }
    }

    vi partial_ans;
    
    if(remaining.size() > 0){
        forn(i, remaining.size()){
            partial_ans.push_back(remaining[i]);
            if(partial_ans.size() == 3){
                ans.push_back({partial_ans[0], partial_ans[1], partial_ans[2]});
                partial_ans.clear();
            }
        }
    }

    for(auto g3: ans){
        cout << get<0>(g3) << ' ' << get<1>(g3) << ' ' << get<2>(g3) << endl; 
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