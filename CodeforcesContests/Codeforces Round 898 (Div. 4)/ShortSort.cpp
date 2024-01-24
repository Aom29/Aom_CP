#include <bits/stdc++.h>

using namespace std;
using p2i = pair<int,int>;                           // Par de enteros
using lli = long long int;

const int SIZE = 1e5 + 1,INF = 1e8 + 1;             // Constantes de tamaño e infinito

void swap(char *a, char *b){
    char aux = *a;
    *a = *b;
    *b = aux;
}

void solve(){
    char sol[3] = {'a', 'b', 'c'};
    char cmp1[3];
    char cmp2[3];
    char cmp3[3];
    char cmp4[3];
    for(int i = 0; i < 3; i++){
        cin >> cmp1[i];
        cmp2[i] = cmp1[i];
        cmp3[i] = cmp1[i];
        cmp4[i] = cmp1[i];
    }

    swap(&cmp2[0], &cmp2[2]);
    swap(&cmp3[0], &cmp3[1]);
    swap(&cmp4[1], &cmp4[2]);
    
    bool yes = false;

    for(int i = 0; i < 3; i++){
        if(cmp1[i] != sol[i]){
            yes = false;
            break;
        }
        else
            yes = true;
    }

    if(!yes){
        for(int i = 0; i < 3; i++){
            if(cmp2[i] != sol[i]){
                yes = false;
                break;
            }
            else
                yes = true;
        }
        if(!yes){
            for(int i = 0; i < 3; i++){
                if(cmp3[i] != sol[i]){
                    yes = false;
                    break;
                }
                else
                    yes = true;
            }
            if(!yes){
                for(int i = 0; i < 3; i++){
                    if(cmp4[i] != sol[i]){
                        yes = false;
                        break;
                    }
                    else
                        yes = true;
                }
            }
        }
    }

    if(yes)
        cout << "YES\n";
    else
        cout << "NO\n";
    

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}