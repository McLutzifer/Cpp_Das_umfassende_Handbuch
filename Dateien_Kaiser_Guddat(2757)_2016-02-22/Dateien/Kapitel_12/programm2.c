int programm2( int n )
   {
   int i, k;
   int z = 0;

   for (i = 1; i <= n; i *= 2)
      {
      for (k = 1; k <= i; k++)
         z++;
      }
   return z;
   }


void main()
   {
   int n;

   for (n = 1; n <= 15; n++)
      printf( "%2d %2d\n", n, programm2( n ));
   }
