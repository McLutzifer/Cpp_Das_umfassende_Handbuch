# include <stdio.h>
# include <stdlib.h>

void bubblesort( int n, int *daten )
   {
   int i, k, t;

   for( i = n - 1; i > 0; i-- )
      {
      for( k = 0; k < i; k++ )
         {
         if( daten[k] > daten[k + 1] )
            {
            t = daten[k];
            daten[k] = daten[k + 1];
            daten[k + 1] = t;
            }
         }
      }
   }


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
   bubblesort( ANZAHL, daten );
   if( pruefen( ANZAHL, daten ) )
      printf( "ok\n" );
   else
      printf( "nicht ok\n" );
   }




