#include<bits/stdc++.h>
using namespace std;



void solve()
{
    string s; cin>>s;
    stack<pair<int, char>> mayusculas;
    stack<pair<int, char>> minusculas;
    string ans;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'B'){
            if(mayusculas.size() > 0){
                mayusculas.pop();
            }
        }
        else if(s[i] == 'b'){
            if(minusculas.size() > 0){
                minusculas.pop();
            }
        }
        else{
            if(islower(s[i])){
                minusculas.push({i, s[i]});
            }
            if(isupper(s[i])){
                mayusculas.push({i, s[i]});
            }
        }
    }

    while(!mayusculas.empty() || !minusculas.empty()){
        if(mayusculas.empty()){
            ans += (minusculas.top()).second;
            minusculas.pop();
        }
        else if(minusculas.empty()){
            ans += (mayusculas.top()).second;
            mayusculas.pop();
        }
        else{
            if(mayusculas.top() < minusculas.top()){
                ans += (minusculas.top()).second;
                minusculas.pop();
            }
            else{
                ans += (mayusculas.top()).second;
                mayusculas.pop();
            }
        }
    }

    for(int i = ans.size()-1; i >= 0; i--){
        cout << ans[i];
    }

    cout << '\n';
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