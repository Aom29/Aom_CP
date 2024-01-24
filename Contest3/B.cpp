#include <bits/stdc++.h>
using namespace std;

int main() {

   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   int n, q;
   cin >> n >> q;

   string cadena, subcadena;
   cin >> cadena;

   //las consultas sonn q

   while (q > 0) {
      int i, j, k;
      cin  >> i >> j >> k;

      // cout << endl;
      // cout << cadena << endl;
      // cout << i << endl << j << endl << k << endl;
      if (k == 0) {
         // Pos creo que solo ordenamos dreecreciente la sub
         sort(cadena.begin() + i - 1, cadena.begin() + j, greater<char>());
      } else {
         // en orden creciente
         sort(cadena.begin() + i - 1, cadena.begin() + j);
      }
      q--;
   }

   cout << cadena << endl;

   return 0;
}