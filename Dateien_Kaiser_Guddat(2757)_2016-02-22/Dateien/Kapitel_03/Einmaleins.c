
# include <stdio.h>
# include <stdlib.h>

/*
** Einmaleins (Kap. 3.9.1)
*/


//void main()
//    {
//    int i, k, produkt;
//
//    for( i = 1; i <= 10; i = i + 1)
//        {
//        for( k = 1; k <= 10; k = k + 1)
//            {
//            produkt = i*k;
//            printf( "  %d mal %d ist %d\n", i, k, produkt);
//            }
//        printf( "\n");
//        }
//    }
//

//void main()
//    {
//    int i, k;
//    int maxi, maxk;
//    int produkt;
//
//    printf( "  Bitte maxi eingeben: ");
//    scanf( "%d", &maxi);
//    printf( "  Bitte maxk eingeben: ");
//    scanf( "%d", &maxk);
//
//    for( i = 1; i <= maxi; i = i + 1)
//        {
//        for( k = 1; k <= maxk; k = k + 1)
//            {
//            produkt = i*k;
//            printf( "  %d mal %d ist %d\n", i, k, i*k);
//            }
//        printf( "\n");
//        }
//    }
//


void main()
   {
   int i, k, produkt;

   printf( "     " );
   for( i = 1; i <= 10; i = i + 1 )
      printf( "  %3d", i );
   printf( "\n" );
   for( i = 1; i <= 55; i++ )
      printf( "-" );
   printf( "\n" );
   for( i = 1; i <= 10; i = i + 1 )
      {
      printf( "%3d |", i );
      for( k = 1; k <= 10; k = k + 1 )
         {
         produkt = i*k;
         printf( "  %3d", produkt );
         }
      printf( "\n" );
      }
   for( i = 1; i <= 55; i++ )
      printf( "-" );
   printf( "\n\n" );
   }



