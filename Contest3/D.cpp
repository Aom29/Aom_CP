#include<bits/stdc++.h>
using namespace std;

const int INF=1e9+1;
void solve()
{
    string s; cin>>s;
    string news;
    int ultmin=-1, ultmay=-1;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='b' && ultmin!=-1)
        {
            news.erase(ultmin,1);
        }
        else if(s[i]=='B' && ultmay!=-1)
        {
            news.erase(ultmay,1);
        }
        else if(s[i]!='b' && s[i]!='B')
            news+=s[i];
        
        for(int j=news.length()-1;j>=0;--j)
        {
            if(isupper(news[j]))
            {
                ultmay=j;
                break;
            }
            ultmay=-1;
        }
        for(int j=news.length()-1;j>=0;--j)
        {
            if(islower(news[j]))
            {
                ultmin=j;
                break;
            }
            ultmay=-1;
        }
        
    }
    cout<<news<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}