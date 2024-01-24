#include <bits/stdc++.h>
using namespace std;

// Because I feel more special
#define u8 char
#define i16 short
#define i32 int
#define i64 long int
#define u16 unsigned short
#define u32 unsigned int
#define u64 unsigned long int

#define f32 float
#define f64 double

typedef pair<int, int> p2i;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<p2i> vp2i;

#define endl "\n"

#define forn(i, n) for (i = 0; i < int(n); ++i)
#define rep(i,k,n) for (i = int(k); i <= int(n); i++)
#define repr(i,k,n) for (i = int(k); i >= int(n); i--)
#define all(x) x.begin(), x.end()
#define pb push_back

const int SIZE = 1e5 + 1,INF = 1e8 + 1;

string addtime(string s, int x){
    int hours = stoi(s.substr(0,2));
    int minutes = stoi(s.substr(3,2));

    minutes += x;
    if(minutes >= 60){
        hours += minutes / 60;
        minutes %= 60;
    }
    if(hours >= 24){
        hours %= 24;
    }
    s[0] = hours / 10 + '0';
    s[1] = hours % 10 + '0';
    s[3] = minutes / 10 + '0';
    s[4] = minutes % 10 + '0';
    return s;
}

bool check(string s){
    // Checks if it is a palindrome
    char a, b;
    a = s[0];
    b = s[4];
    if(a == b)
    {
        a = s[1];
        b = s[3];
        if(a == b)
        {
            return true;
        }
    }
    return false;
}

void solution()
{
    int result = 0;
    string s;
    string w;
    cin >> s;
    w = s;
    int x;
    cin >> x;
    int i;
    do{
        if(check(s)){
            result++;
        }
        s = addtime(s, x);
    }while(s != w);

    cout << result << endl;
}

int main()
{
    int T;cin>>T;while(T--)
        solution();
    return 0;
}