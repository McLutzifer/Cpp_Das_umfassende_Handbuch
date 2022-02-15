int funktion2( int n )
   {
   int x, y;
   int k = 0;

   for (x = 0, y = 1; x <= n; x += y, y += 2)
      k++;
   return k - 1;
   }


void main()
   {
   int n;

   for (n = 1; n <= 20; n++)
      printf( "%2d %2d\n", n, funktion2( n ));
   }
