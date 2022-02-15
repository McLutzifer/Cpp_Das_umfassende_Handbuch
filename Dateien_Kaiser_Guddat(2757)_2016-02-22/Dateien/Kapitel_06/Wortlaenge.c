# include <stdio.h>
# include <stdlib.h>

/*
** Wortlaenge
*/

void main()
   {
   char wort[100];
   int i;

   printf( "Wort: " );
   scanf( "%s", wort );

   for( i = 0; wort[i] != 0; i++ )
      ;

   printf( "%s hat %d Zeichen\n", wort, i );
   }

