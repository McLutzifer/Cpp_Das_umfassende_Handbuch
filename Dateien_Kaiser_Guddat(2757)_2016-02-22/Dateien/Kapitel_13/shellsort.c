# include <stdio.h>
# include <stdlib.h>
# include <math.h>

/*
** Shellsort (Kap. 13.4)
*/

void insertion_h_sort( int n, int *daten, int h )
   {
   int i, k, v;

   for( i = h; i < n; i++ )
      {
      v = daten[i];
      for( k = i; ( k >= h ) && ( daten[k - h] > v ); k -= h )
         daten[k] = daten[k - h];
      daten[k] = v;
      }
   }


void shellsort1( int n, int *daten )
   {
   int h;

   for( h = 1; h <= n / 9; h = 3 * h + 1 )
      ;
   for( ; h > 0; h /= 3 )
      insertion_h_sort( n, daten, h );
   }


void shellsort( int n, int *daten )
   {
   int i, k, h, v;

   for( h = 1; h <= n / 9; h = 3 * h + 1 )
      ;
   for( ; h > 0; h /= 3 )
      {
      for( i = h; i < n; i++ )
         {
         v = daten[i];
         for( k = i; ( k >= h ) && ( daten[k - h] > v ); k -= h )
            daten[k] = daten[k - h];
         daten[k] = v;
         }
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
   shellsort( ANZAHL, daten );
   if( pruefen( ANZAHL, daten ) )
      printf( "ok\n" );
   else
      printf( "nicht ok\n" );
   }
