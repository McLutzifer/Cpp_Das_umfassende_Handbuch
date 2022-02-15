
# include <stdio.h>
# include <stdlib.h>

/*
** Heron Verfahren
*/

void main()
   {
   float a, w;

   printf( "  Bitte Zahl eingeben: " );
   scanf( "%f", &a );

   w = a;
   for( ;; )
      {
      w = ( w + a / w ) / 2;
      printf( "  %f\n", w );
      if( w*w - a < 0.001 )
         break;
      }
   }

