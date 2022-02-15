# include <stdio.h>
# include <stdlib.h>

/*
** Permutationen
*/

void perm( int anz, char array[], int start )
   {
   int i;
   char sav;

   if( start < anz )
      {
      sav = array[start];
      for( i = start; i < anz; i = i + 1 )
         {
         array[start] = array[i];
         array[i] = sav;
         perm( anz, array, start + 1 );
         array[i] = array[start];
         }
      array[start] = sav;
      }
   else
      printf( "%s\n", array );
   }


void main()
   {
   char haufen[5] = "TEWR";

   printf( "Vorher:  %s\n", haufen );

   perm( 4, haufen, 0 );

   printf( "Nachher: %s\n", haufen );

   printf( "%d\n", 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 );
   }



