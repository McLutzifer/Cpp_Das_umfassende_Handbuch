int minimum( int a, int b )
   {
   if (a < b)
      return a;

   return b;
   }


int maximum( int a, int b )
   {
   if (a > b)
      return a;

   return b;
   }


int suche( int anz, int *daten, int fkt( int, int ))
   {
   int i, m;

   m = daten[0];
   for (i = 1; i < anz; i++)
      m = fkt( m, daten[i] );
   return m;
   }


void main()
   {
   int zahlen[10] = {1, -12, 31, 17, -11, 0, 22, 9, 4, -7};
   int min, max;

   min = suche( 10, zahlen, minimum );
   printf( "Minimum: %d\n", min );
   max = suche( 10, zahlen, maximum );
   printf( "Maximum: %d\n", max );
   }
