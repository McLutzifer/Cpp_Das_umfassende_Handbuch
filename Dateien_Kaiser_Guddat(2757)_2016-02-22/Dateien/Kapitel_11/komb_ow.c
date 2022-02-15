# include <stdio.h>
# include <stdlib.h>

/*
** Kombinationen ohne Wiederholungen
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

void komb_ow( int n, int k, int array[], int x, int min )
   {
   int i;

   if( x < k )
      {
      for( i = min; i <= n - k + x; i++ )
         {
         array[x] = i;
         komb_ow( n, k, array, x + 1, i + 1 );
         }
      }
   else
      print_array( k, array );
   }

void main()
   {
   int array[2];

   printf( "4-2-Kombinationen\nohne Wiederholungen\n" );
   komb_ow( 4, 2, array, 0, 0 );
   }


