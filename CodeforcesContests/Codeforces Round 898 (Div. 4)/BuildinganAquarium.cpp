    #include <bits/stdc++.h>
     
    using namespace std;
    using p2i = pair<int,int>;                           // Par de enteros
    using lli = long long int;
    int contt = 0;
     
    const int SIZE = 1e5 + 1;
    const lli INF = 2e10 + 1;             // Constantes de tamaño e infinito
     
    bool valid(lli m, int x, int k, int coral[]){
        int cont = 0;
        for(int i = 0; i < k; i++){
            if(cont > x)
                return false;
            if(coral[i] < m)
                cont += m-coral[i];
        }
        return cont <= x;
    }
     
    int binarySearch(lli n, int x, int *coral, int k){
        lli l = 0, r = n - 1, m;
        while(l < r){
            m = (l + r) / 2;
            if(valid(m, x, k, coral)){
                //cout << m << " " << r-1 << "\n";
                //r = m;
                l = m + 1;
            }
                
            else
                //l = m + 1;
                r = m;
        }
        return r - 1;
    }
     
    void solve(){
        int n, x;
        cin >> n >> x;
        int *coral = NULL;
        coral = (int*)malloc(n*sizeof(int));
        for(int i = 0; i < n; i++)
            cin >> coral[i];
        cout << binarySearch(INF, x, coral, n) << "\n";
     
    }
     
    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
     
        int t; cin >> t;
     
        while(t--)
            solve();
     
        return 0;
    }