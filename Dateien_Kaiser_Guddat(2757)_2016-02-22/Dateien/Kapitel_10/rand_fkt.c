# include <stdlib.h>

void main()
   {
   int seed, wurf, i;

   seed = 4711;
   srand( seed );
   for (i = 1; i <= 5; i++)
      {
      wurf = rand() % 6 + 1;
      printf( "%d. Wurf: %d\n", i, wurf );
      }
   }
