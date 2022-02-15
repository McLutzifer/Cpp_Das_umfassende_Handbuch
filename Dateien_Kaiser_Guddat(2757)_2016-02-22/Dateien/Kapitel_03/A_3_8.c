# include <stdio.h>
# include <stdlib.h>


void main()
   {
   int a, b;
   int q, v;

   printf( "a: " );
   scanf( "%d", &a );
   printf( "b: " );
   scanf( "%d", &b );

   printf( "Denk dir eine Zahl zwischen %d und %d\n", a, b );

   for( ;; )
      {
      q = ( a + b ) / 2;
      printf( "Ist es %d? ( 0 gleich, -1 kleiner, 1 groesser): ", q );
      scanf( "%d", &v );
      if( v == 0 )
         break;
      if( v < 0 )
         b = q - 1;
      else
         a = q + 1;
      }
   }
