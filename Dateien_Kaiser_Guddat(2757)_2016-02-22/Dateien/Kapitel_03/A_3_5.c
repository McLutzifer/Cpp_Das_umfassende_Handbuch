# include <stdio.h>
# include <stdlib.h>


void main()
   {
   int min, max;
   int i;

   printf( "Minimum: " );
   scanf( "%d", &min );
   printf( "Maximum: " );
   scanf( "%d", &max );

   for( i = min; i <= max; i++ )
      {
      if( i % 7 == 0 )
         printf( "%d ist durch 7 teilbar\n", i );
      }
   }
