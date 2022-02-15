# include <limits.h>
# include "maximum.h"

int absolutes_maximum = INT_MIN;

int maximum( int a, int b )
   {
   int max;

   if (a > b)
      max = a;
   else
      max = b;
   if (max > absolutes_maximum)
      absolutes_maximum = max;
   }
