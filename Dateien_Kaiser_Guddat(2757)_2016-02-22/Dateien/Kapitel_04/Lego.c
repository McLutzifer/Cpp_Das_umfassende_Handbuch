# include <stdio.h>
# include <stdlib.h>

/*
** Treppe aus Legosteinen (Kap. 4.2)
*/

void main()
   {
   int max = 9;
   int steine = 0;
   int h;

   for( h = 1; h <= max; h = h + 1 )
      {
      steine = steine + h;
      printf( "  Hoehe: %d, Steine: %d\n", h, steine );
      }
   }

