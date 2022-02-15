# include <stdio.h>
# include <stdlib.h>
# include <math.h>

/*
** Selectionsort (Kap. 13.2)
*/


void selectionsort( int n, int *daten )
   {
   int i, k, t, min;

   for( i = 0; i < n - 1; i++ )
      {
      min = i;
      for( k = i + 1; k < n; k++ )
         {
         if( daten[k] < daten[min] )
            min = k;
         }
      t = daten[min];
      daten[min] = daten[i];
      daten[i] = t;
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
   selectionsort( ANZAHL, daten );
   if( pruefen( ANZAHL, daten ) )
      printf( "ok\n" );
   else
      printf( "nicht ok\n" );
   }
