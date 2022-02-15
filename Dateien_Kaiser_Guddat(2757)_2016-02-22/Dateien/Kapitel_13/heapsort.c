# include <stdio.h>
# include <stdlib.h>
# include <math.h>

/*
** Heapsort (Kap. 13.6)
*/


void adjustheap( int n, int *daten, int k )
   {
   int j, v;

   v = daten[k];
   while( k < n / 2 )
      {
      j = 2 * k + 1;
      if( ( j < n - 1 ) && ( daten[j] < daten[j + 1] ) )
         j++;
      if( v >= daten[j] )
         break;
      daten[k] = daten[j];
      k = j;
      }
   daten[k] = v;
   }

void heapsort( int n, int *daten )
   {
   int k, t;

   for( k = n / 2; k; )
      adjustheap( n, daten, --k );

   while( --n )
      {
      t = daten[0];
      daten[0] = daten[n];
      daten[n] = t;
      adjustheap( n, daten, 0 );
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
   heapsort( ANZAHL, daten );
   if( pruefen( ANZAHL, daten ) )
      printf( "ok\n" );
   else
      printf( "nicht ok\n" );
   }
