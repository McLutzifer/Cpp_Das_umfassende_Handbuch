# include "set.h"

/*
** Menge Testrahmen (Kap. 20.9.1)
*/
int main() {
   set A;
   A += 2;
   A += 4;
   A += 6;
   A += 8;
   A += 10;
   A += 12;
   set B;
   B += 2;
   B += 4;
   B += 6;
   B += 7;
   B += 9;
   B += 11;
   cout << " A = " << A;
   cout << " B = " << B << '\n';
   cout << " A + B = " << A + B;
   cout << " A * B = " << A*B;
   cout << " A – B = " << A - B;

   cout << "\n";

   if( !( A*B ) )
      cout << "Der Durchschnitt von A und B ist leer\n\n";
   else
      cout << "Der Durchschnitt von A und B ist nicht leer\n\n";
   if( !( A <= B ) )
      cout << "A ist keine Teilmenge von B\n\n";
   cout << "Berechnung einiger Formeln\n";
   cout << "(A +1) * ~(B + 8) = "
      << ( A + 1 ) * ~( B + 8 );
   cout << "((A + 1) * ~(B + 8)) – 10 = " << ( ( A + 1 ) * ~( B + 8 ) ) - 10;
   cout << "((A + 1) * ~(B + 8) – 10) + B = \n" << ( ( A + 1 ) * ~( B + 8 ) - 10 ) + B;
   cout << "\n";
   if( ( A*B + 15 ) <= ( B + 15 ) )
      cout << " A*B+15 ist Teilmenge von B+15\n\n";

   A += ( B - 11 );
   cout << "A = " << A;
   A *= ( B -= 2 );
   cout << "A = " << A;
   cout << "B = " << B;

   return 0;
   }