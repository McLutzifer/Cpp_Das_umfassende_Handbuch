int funktion1( int n )
   {
   int x;
   int k = 0;

   for (x = 1; x <= n; x *= 2)
      k++;
   return k - 1;
   }


void main()
   {
   int n;

   for (n = 1; n <= 20; n++)
      printf( "%2d %2d\n", n, funktion1( n ));
   }
