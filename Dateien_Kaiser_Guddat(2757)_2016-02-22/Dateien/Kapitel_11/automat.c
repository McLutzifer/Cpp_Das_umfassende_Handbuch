# include <stdio.h>
# include <stdlib.h>

/*
** Geldautomat (Kap. 10.3.2)
*/

static int noten[7] = { 500, 200, 100, 50, 20, 10, 5 };
int betrag;
int pruefungen;

int pruefe( int k, int array[] )
   {
   int i;
   int summe;

   for( i = 0, summe = 0; i < k; i++ )
      summe += noten[array[i]];
   pruefungen++;
   return ( summe == betrag );
   }

static int komb_mw( int n, int k, int array[], int x, int min )
   {
   int i;

   if( x < k )
      {
      for( i = min; i < n; i++ )
         {
         array[x] = i;
         if( komb_mw( n, k, array, x + 1, i ) )
            return 1;
         }
      return 0;
      }
   else
      return pruefe( k, array );
   }


void main()
   {
   int array[20];
   int k, i;

   for( ;; )
      {
      printf( "Betrag: " );
      scanf( "%d", &betrag );

      if( betrag <= 0 )
         break;

      pruefungen = 0;
      for( k = 1; k <= 20; k++ )
         {
         if( komb_mw( 7, k, array, 0, 0 ) )
            {
            printf( "Auszahlung: " );
            for( i = 0; i < k; i++ )
               printf( "%d ", noten[array[i]] );
            printf( "\n" );
            break;
            }
         }
      if( k > 20 )
         printf( "Keine Auszahlung moeglich\n" );
      printf( "Es wurden %d Pruefungen durchgefuehrt\n\n", pruefungen );
      }
   }



