# include <stdio.h>
# include <stdlib.h>


void main()
   {
   int zahl1, zahl2;
   int summe, differenz, produkt, quotient, rest;

   printf( "1. Zahl: " );
   scanf( "%d", &zahl1 );
   printf( "2. Zahl: " );
   scanf( "%d", &zahl2 );

   summe = zahl1 + zahl2;
   differenz = zahl1 - zahl2;
   produkt = zahl1 * zahl2;
   quotient = zahl1 / zahl2;
   rest = zahl1 % zahl2;

   printf( "Summe     %d + %d = %d\n", zahl1, zahl2, summe );
   printf( "Differenz %d - %d = %d\n", zahl1, zahl2, differenz );
   printf( "Produkt   %d * %d = %d\n", zahl1, zahl2, produkt );
   printf( "Quotient  %d / %d = %d Rest %d\n", zahl1, zahl2, quotient, rest );
   }
