# include <stdio.h>
# include <stdlib.h>

/*
** Bruchrechung
*/


int ggt( int a, int b )
   {
   for( ; a != b; )
      {
      if( a > b )
         a = a - b;
      else
         b = b - a;
      }
   return a;
   }

void kuerzen( int b[] )
   {
   int gt;

   gt = ggt( b[0], b[1] );
   b[0] = b[0] / gt;
   b[1] = b[1] / gt;
   }

void addieren( int b1[], int b2[], int erg[] )
   {
   erg[0] = b1[0] * b2[1] + b2[0] * b1[1];
   erg[1] = b1[1] * b2[1];
   kuerzen( erg );
   }

void main()
   {
   int bruch1[2], bruch2[2], ergebnis[2];

   printf( "Bruch1: " );
   scanf( "%d/%d", &bruch1[0], &bruch1[1] );
   printf( "Bruch2: " );
   scanf( "%d/%d", &bruch2[0], &bruch2[1] );

   addieren( bruch1, bruch2, ergebnis );

   printf( "Ergebnis: %d/%d\n", ergebnis[0], ergebnis[1] );
   }



