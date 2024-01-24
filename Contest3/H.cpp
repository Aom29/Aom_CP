#include <bits/stdc++.h>
using namespace std;

int main() {
   int n_tests = 0;
   cin >> n_tests;

   while (n_tests > 0) {
      string cam1, cam2;
      int tam1, tam2;

      cin >> cam1 >> cam2;
      tam1 = cam1.length() - 1;
      tam2 = cam2.length() - 1;

      char fin1, fin2;
      fin1 = cam1[tam1];
      fin2 = cam2[tam2];

      // cout << endl;
      // cout << fin1 << endl;
      // cout << fin2;

      if (fin1 == 'S' && fin2 != 'S') {
         cout << '<' << endl;
      }
      if (fin1 != 'S' && fin2 == 'S') {
         cout << '>' << endl;
      }

      if (fin1 == fin2 && (fin1 == 'S' && fin2 == 'S')) {
         if (tam1 > tam2) {
            cout << '<' << endl;
         }
         else if (tam1 == tam2)
         {
            cout << '=' << endl;
         }
         else if (tam1 < tam2) {
            cout << '>' << endl;
         } else {
            cout << "comollegue aqui xd";
         }
      }

      if (fin1 == fin2 && !(fin1 == 'S' && fin2 == 'S')) {
         if (tam1 > tam2) {
            cout << '>' << endl;
         }
         else if (tam1 == tam2)
         {
            cout << '=' << endl;
         }
         else if (tam1 < tam2) {
            cout << '<' << endl;
         } else {
            cout << "comollegue aqui xd";
         }
      }
      if (fin1 != fin2 && !(fin1 == 'S' && fin2 == 'S')) {
         if (fin1 == 'M' && fin2 == 'L') {
            cout << '<' << endl;
         }
         else if (fin1 == 'L' && fin2 == 'M') {
            cout << '>' << endl;
         }

      }


      n_tests--;
   }

   return 0;
}