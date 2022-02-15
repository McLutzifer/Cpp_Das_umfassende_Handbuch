int programm6( int n )
   {
   int i, k, m;
   int z = 0;

   for (i = 1, m = 1; i <= n; i++, m *= 2)
      {
      for (k = 1; k <= m; k++)
         z++;
      }
   return z;
   }


void main()
   {
   int n;

   for (n = 1; n <= 15; n++)
      printf( "%2d %2d\n", n, programm6( n ));
   }
