# include <stdio.h>
# include <stdlib.h>

/*
** Permutationen ohne Wiederholungen
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

static void perm( int anz, int array[], int start )
   {
   int i, sav;

   if( start < anz )
      {
      sav = array[start];
      for( i = start; i < anz; i++ )
         {
         array[start] = array[i];
         array[i] = sav;
         perm( anz, array, start + 1 );
         array[i] = array[start];
         }
      array[start] = sav;
      }
   else
      print_array( anz, array );
   }


void perm_ow( int n, int k, int array[], int x, int min )
   {
   int i;

   if( x < k )
      {
      for( i = min; i <= n - k + x; i++ )
         {
         array[x] = i;
         perm_ow( n, k, array, x + 1, i + 1 );
         }
      }
   else
      perm( k, array, 0 );
   }



void main()
   {
   int array[2];

   printf( "4-2-Permutationen\nohne Wiederholungen\n" );
   perm_ow( 4, 2, array, 0, 0 );
   }


