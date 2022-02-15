# include <cstdlib>
# include <iostream>
# include <cstring> 
# include "komplex.h"

using namespace std;

void main()
   {
   float re1, im1, re2, im2;
   float a = 1;
   char befehl[10];
   cout << " Abfrage der Komplexen Zahlen: \n\n";
   cout << " 1. komplexe Zahl [x]: \n";
   cout << " Realteil: ";
   cin >> re1;
   cout << " Imaginaerteil: ";
   cin >> im1;

   komplex Z1( re1, im1 ); // 1. komplexe Zahl angelegt

   cout << " 2. komplexe Zahl [y]: \n";
   cout << " Realteil: ";
   cin >> re2;
   cout << " Imaginaerteil: ";
   cin >> im2;

   komplex Z2( re2, im2 ); // 2. komplexe Zahl angelegt

   cout << " Konstante a: ";
   cin >> a;

   cout << "\n Die von Ihnen eingegebenen Zahlen: \n\n";
   cout << " x = " << Z1 << "\n"; // Ausgabe beider Zahlen
   cout << " y = " << Z2 << "\n";
   cout << " a =  " << a << "\n\n"; // Ausgabe Konstante

   cout << " Geben Sie nun einfach die gewuenschten Operationen ein. [ q = ENDE ]\n\n ";

   komplex Z; // Hilfszahl

   for( ;; )
      {

      cout << "Befehl: ";
      cin >> befehl;


      if( befehl[0] == 'q' )
         {
         cout << "\n\t PROGRAMMENDE \n\n";
         break;
         }

      if( ( strstr( befehl, "x+y" ) ) || ( strstr( befehl, "y+x" ) ) )
         {
         Z = Z1 + Z2;
         cout << "\n" << " x + y = " << Z << "\n ";
         continue;
         }

      if( ( strstr( befehl, "x-y" ) ) )
         {
         Z = Z1 - Z2;
         cout << "\n" << " x - y = " << Z << "\n ";
         continue;
         }

      if( ( strstr( befehl, "y-x" ) ) )
         {
         Z = Z2 - Z1;
         cout << "\n" << " x - y = " << Z << "\n ";
         continue;
         }

      if( ( strstr( befehl, "x*y" ) ) || ( strstr( befehl, "y*x" ) ) )
         {
         Z = Z1 * Z2;
         cout << "\n" << " x * y = " << Z << "\n ";
         continue;
         }

      if( ( strstr( befehl, "a*x" ) ) || ( strstr( befehl, "x*a" ) ) )
         {
         Z = Z1 * a;
         cout << "\n" << " a * y = " << Z << "\n ";
         continue;
         }


      if( ( strstr( befehl, "a*y" ) ) || ( strstr( befehl, "y*a" ) ) )
         {
         Z = Z2 * a;
         cout << "\n" << " a * y = " << Z << "\n ";
         continue;
         }


      if( ( strstr( befehl, "y/a" ) ) )
         {
         Z = Z2 / a;
         cout << "\n" << " y" << " /" << " a = " << Z << "\n ";
         continue;
         }

      if( ( strstr( befehl, "x/a" ) ) )
         {
         Z = Z1 / a;
         cout << "\n" << " x" << " /" << " a = " << Z << "\n ";
         continue;
         }

      if( strstr( befehl, "|x|" ) )
         {
         float ab;

         ab = abs( Z1 );

         cout << "\n" << " |x| = " << ab << "\n\n ";
         continue;
         }

      if( strstr( befehl, "|y|" ) )
         {
         float ab;

         ab = abs( Z2 );

         cout << "\n" << " |y| = " << ab << "\n\n ";
         continue;
         }
      }
   }
