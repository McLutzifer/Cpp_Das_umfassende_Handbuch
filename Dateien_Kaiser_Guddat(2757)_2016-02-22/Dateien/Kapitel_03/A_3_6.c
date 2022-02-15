# include <stdio.h>
# include <stdlib.h>


void main()
   {
   int hoehe;
   int steine, i;

   printf( "Hoehe: " );
   scanf( "%d", &hoehe );

   for( i = 1, steine = 0; i <= hoehe; i++ )
      steine += i;
   printf( "Eine Treppe der Hoehe %d hat %d Steine\n", hoehe, steine );
   }
