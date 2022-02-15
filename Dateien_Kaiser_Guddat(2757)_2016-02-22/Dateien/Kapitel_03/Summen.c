# include <stdio.h>
# include <stdlib.h>

/*
** Das dritte C-Programm (Kap. 3.9.3)
*/

void main()
   {
   int anzahl;
   int summand, psum, nsum;
   int z;

   printf( "   Wie viele Zahlen sollen eingegeben werden: " );
   scanf( "%d", &anzahl );

   psum = 0;
   nsum = 0;

   for( z = 1; z <= anzahl; z = z + 1 )
      {
      printf( "  %d. Zahl: ", z );
      scanf( "%d", &summand );
      if( summand > 0 )
         psum = psum + summand;
      if( summand < 0 )
         nsum = nsum + summand;
      }

   printf( "\n  Die Summe aller positiven Eingaben ist: %d\n", psum );
   printf( "  Die Summe aller negativen Eingaben ist: %d\n", nsum );
   printf( "  Die Gesamtsumme ist: %d\n", psum + nsum );
   }

