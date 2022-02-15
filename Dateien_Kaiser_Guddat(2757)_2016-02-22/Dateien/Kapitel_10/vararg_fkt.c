# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int summe( int anz, ... )
   {
   va_list ap;
   int     sum;
   int     summand;

   va_start( ap, anz );
   for (sum = 0; anz; anz--)
      {
      summand = va_arg( ap, int );
      sum    += summand;
      }
   va_end( ap );
   return sum;
   }


int main()
   {
   int a = 1, b = 2, c = 3, d = 4;
   int x;

   x = summe( 2, a, b );
   printf( "%d\n", x );
   x = summe( 3, a, b, c );
   printf( "%d\n", x );
   x = summe( 4, a, b, c, d );
   printf( "%d\n", x );
   }
