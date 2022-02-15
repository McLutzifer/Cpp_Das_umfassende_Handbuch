# include <stdio.h>
# include <stdlib.h>

/*
** Geldautomat (Kap. 10.3.2)
*/


void auszahlung( int betrag )
   {
   int noten[7] = { 500, 200, 100, 50, 20, 10, 5 };
   int n;
   int rest;

   printf( "Auszahlung: " );
   for( n = 0, rest = betrag; rest >= 5; )
      {
      if( noten[n] <= rest )
         {
         printf( "%d ", noten[n] );
         rest -= noten[n];
         }
      else
         n++;
      }
   printf( "\n" );
   if( rest )
      printf( "Rest %d Euro kann nicht ausgezahlt werden\n", rest );
   }

void main()
   {
   int betrag;

   for( ;; )
      {
      printf( "Betrag: " );
      scanf( "%d", &betrag );

      if( betrag <= 0 )
         break;

      auszahlung( betrag );
      }
   }



