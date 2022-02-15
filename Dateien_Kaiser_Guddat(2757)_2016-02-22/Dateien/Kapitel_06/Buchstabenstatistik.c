# include <stdio.h>
# include <stdlib.h>

/*
** Buchstabenstatistik
*/

void main()
   {
   char zeile[100];
   int statistik[26];
   int i;

   for( i = 0; i < 26; i++ )
      statistik[i] = 0;

   printf( "Text: " );
   fgets( zeile, 100, stdin );

   for( i = 0; zeile[i] != 0; i++ )
      {
      if( ( zeile[i] >= 'a' ) && ( zeile[i] <= 'z' ) )
         statistik[zeile[i] - 'a']++;
      }

   printf( "\nAuswertung:\n" );
   for( i = 0; i < 26; i++ )
      printf( "%c: %d\n", 'a' + i, statistik[i] );
   }

