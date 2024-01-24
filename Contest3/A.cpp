#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   int t;
   cin >> t;
   vector<int> valores;

   while (t > 0)
   {
      string tipo;
      int val;
      cin  >> tipo;

      if (tipo == "PUSH") {
         cin >> val; 
         valores.push_back(val);
      }
      else if (tipo == "POP" && !valores.empty())
      {
         valores.pop_back();
      }
      else if (tipo == "MIN") {
         int min = *min_element(valores.begin(), valores.end());
         if(!valores.empty())
            cout << min << '\n';
         else
            cout << "EMPTY";
      }

      t--;
   }

   return 0;
}