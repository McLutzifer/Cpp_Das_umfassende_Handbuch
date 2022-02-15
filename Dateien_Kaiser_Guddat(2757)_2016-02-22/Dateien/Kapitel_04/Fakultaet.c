# include <stdio.h>
# include <stdlib.h>

/*
**
*/

void main()
   {
   int max = 9;
   int f = 1;
   int n;

   for( n = 1; n <= max; n = n + 1 )
      {
      f = f * n;
      printf( " %d! = %d\n", n, f );
      }
   }

