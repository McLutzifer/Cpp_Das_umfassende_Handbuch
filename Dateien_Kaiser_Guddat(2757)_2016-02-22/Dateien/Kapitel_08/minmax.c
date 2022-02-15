void minmax( int anz, int daten[], int *pmin, int *pmax )
   {
   int i, min, max;

   min = daten[0];
   max = daten[0];
   for (i = 1; i < anz; i++)
      {
      if (daten[i] < min)
         min = daten[i];
      if (daten[i] > max)
         max = daten[i];
      }
   *pmin = min;
   *pmax = max;
   }


void main()
   {
   int zahlen[10] = {1, -12, 31, 17, -11, 0, 22, 9, 4, -7};
   int min, max;

   minmax( 10, zahlen, &min, &max );
   printf( "Minimum: %d\n", min );
   printf( "Maximum: %d\n", max );
   }
