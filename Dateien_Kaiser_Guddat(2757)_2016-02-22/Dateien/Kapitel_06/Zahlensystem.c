# include <stdio.h>
# include <stdlib.h>

/*
** Schaltung (Kap. 5.6.2)
*/

//void main()
//    {
//    int zahl = 4711;
//    int basis = 13;
//    int z;
//    //for( basis = 2; basis <= 10; basis++)
//    //    {
//        printf( "  Basis: %d\n", basis);
//        printf( "  -------------------\n");
//        for( z = zahl ; z != 0; z = z/basis) 
//            printf( "  %4d = %4d*%d + %2d\n", z, z/basis, basis, z%basis);
//        printf( "  -------------------\n\n");
//        //}
//    }

void main()
   {
   int zahl = 4711;
   int basis = 2;
   int z;

   printf( "  Basis: %d\n", basis );
   printf( "  -------------------\n" );
   for( z = zahl; z != 0; z = z / basis )
      printf( "  %4d = %4d*%d + %2d\n", z, z / basis, basis, z%basis );
   printf( "  -------------------\n\n" );
   }

