# include <stdio.h>
# include <stdlib.h>
# include <math.h>

/*
** Insertionsort (Kap. 13.3)
*/


void insertionsort( int n, int *daten )
   {
   int i, k, v;

   for( i = 1; i < n; i++ )
      {
      v = daten[i];

      for( k = i; ( k >= 1 ) && ( daten[k - 1] > v ); k-- )
         daten[k] = daten[k - 1];

      daten[k] = v;
      }
   }

/*
** Testrahmen
*/


static void testdaten( int n, int *daten )
   {
   int i;

   for( i = 0; i < n; i++ )
      daten[i] = rand() % n;
   }

static int pruefen( int n, int *daten )
   {
   int i;

   for( i = 0; i < n - 1; i++ )
      {
      if( daten[i] > daten[i + 1] )
         return 0;
      }
   return 1;
   }

# define ANZAHL 100

void main()
   {
   int daten[ANZAHL];

   srand( 4711 );
   testdaten( ANZAHL, daten );
   insertionsort( ANZAHL, daten );
   if( pruefen( ANZAHL, daten ) )
      printf( "ok\n" );
   else
      printf( "nicht ok\n" );
   }
