int *maximum( int *x, int *y )
   {
   if (*x > *y)
      return x;
   else
      return y;
   }


void main()
   {
   int a = 1;
   int b = 2;
   int c;

   c = *maximum( &a, &b );
   printf( "a = %d, b = %d, c = %d\n", a, b, c );
   }
