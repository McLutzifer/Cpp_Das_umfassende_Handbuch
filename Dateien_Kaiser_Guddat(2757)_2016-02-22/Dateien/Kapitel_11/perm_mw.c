# include <stdio.h>
# include <stdlib.h>

/*
** Permutationen mit Wiederholungen
*/

static void print_array( int k, int array[] )
   {
   static int count = 0;
   int i;

   printf( "%3d: (", ++count );
   for( i = 0; i < k - 1; i++ )
      printf( "%2d,", array[i] );
   printf( "%2d)\n", array[k - 1] );
   }

void perm_mw( int n, int k, int array[], int x )
   {
   int i;

   if( x < k )
      {
      for( i = 0; i < n; i++ )
         {
         array[x] = i;
         perm_mw( n, k, array, x + 1 );
         }
      }
   else
      print_array( k, array );
   }

void main()
   {
   int array[2];

   printf( "4-2-Permutationen\nmit Wiederholungen\n" );
   perm_mw( 4, 2, array, 0 );
   }

