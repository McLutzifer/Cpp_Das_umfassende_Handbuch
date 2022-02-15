# include <math.h>

void main()
   {
   double x, y, z;

   x = 1.2;
   y = 3.4;
   z = sqrt( x * x + y * y );
   printf( "z = %f\n", z );
   z = sqrt( exp( x ) + y );
   printf( "z = %f\n", z );
   z = fabs( pow( sin( x ) + cos( y * y ), 5 ));
   printf( "z = %f\n", z );
   }
