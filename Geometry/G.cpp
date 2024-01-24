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

const double SIZE = 1e5 + 1,INF = 1e15 + 1;

double dist(ld a, ld b, ld c, ld d){
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

void solve(){
    ld R, x1, y1, x2, y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;
    cout << setprecision(15);

    if(dist(x1, y1, x2, y2) > R){
        cout << x1 << ' ' << y1 << ' ' << R;
        return;
    }


    if(x1 == x2){
        ld xe = x1;
        ld ye;
        if(y1 > y2){
            ye = y1 + R;
        }
        else{
            ye = y1 - R;
        }

        ld cx = (x2+xe)/2;
        ld cy = (y2+ye)/2;

        ld r = dist(cx, cy, x2, y2);

        cout << cx << ' ' << cy << ' ' << r;
        return;

    }

    if(y1 == y2){
        ld ye = y1;
        ld xe;
        if(x1 > x2){
            xe = x1 + R;
        }
        else{
            xe = x1 - R;
        }


        ld cx = (x2+xe)/2;
        ld cy = (y2+ye)/2;

        ld r = dist(cx, cy, x2, y2);

        cout << cx << ' ' << cy << ' ' << r;
        return;

    }


    ld m = (y2-y1)/(x2-x1);
    ld xe1 = x1 + R / sqrt((1+m*m));
    ld xe2 = x1 - R / sqrt((1+m*m));
    ld ye1 = y1 + m*(xe1-x1);
    ld ye2 = y1 + m*(xe2-x1);
    ld xe, ye;

    // (a+c*c*c+a*c+sqrt(c*c*(c*c+1)*R*R))/(c*(c*c+1));

    // cout << xe1 << ' ' << ye1 << endl;

    if(dist(xe1, ye1, x2, y2) > dist(xe2, ye2, x2, y2)){
        xe = xe1;
        ye = ye1;
    }
    else{
        xe = xe2;
        ye = ye2;
    }

    // cout << xe << ' ' << ye << endl;

    ld cx = (x2+xe)/2;
    ld cy = (y2+ye)/2;

    ld r = dist(cx, cy, x2, y2);

    cout << cx << ' ' << cy << ' ' << r;


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;

    // while(t--)
        solve();

    return 0;
}