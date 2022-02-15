# include <stdio.h>
# include <stdlib.h>

/*
** Kugelspiel (Kap. 5.6.1)
*/

void main()
   {
   int A, B, C, D;
   int z1, z2;

   for( A = 0; A <= 1; A++ )
      {
      for( B = 0; B <= 1; B++ )
         {
         for( C = 0; C <= 1; C++ )
            {
            for( D = 0; D <= 1; D++ )
               {
               z1 = A&&B || ( A&&!B || !A&&C ) && D;
               z2 = !A&&!B&&C&&D || !A&&B&&C&&D || A&&!B&&!C&&D || A&&!B&&C&&D || A&&B&&!C&&!D || A&&B&&!C&&D || A&&B&&C&&!D || A&&B&&C&&D;
               printf( "%d %d %d %d | %d %d\n", A, B, C, D, z1, z2 );
               }
            }
         }
      }
   }
