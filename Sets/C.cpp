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
    priority_queue<int> maxheap;
    priority_queue<int, vi, greater<int>> minheap;
    int a;
    cout << fixed << setprecision(1);
    cin >> a;
    minheap.push(a);
    cout << (float)minheap.top();
    if(1 != n)
        cout << endl;

    forr(i, 2, n){
        cin >> a;
        if(a > minheap.top())
            minheap.push(a);
        else
            maxheap.push(a);

        if(i % 2 == 0){
            if(minheap.size() > maxheap.size()){
                maxheap.push(minheap.top());
                minheap.pop();
            }
            if(maxheap.size() > minheap.size()){
                minheap.push(maxheap.top());
                maxheap.pop();
            }
            cout << (float)(maxheap.top()+ minheap.top())/2;
        }else{
            if(minheap.size() > maxheap.size())
                cout << (float)minheap.top();
            else
                cout << (float)maxheap.top();
        }
        if(i != n)
            cout << endl;
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