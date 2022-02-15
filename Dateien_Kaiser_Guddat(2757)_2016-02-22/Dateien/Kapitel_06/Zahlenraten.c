# include <stdio.h>
# include <stdlib.h>

/*
** Zahlenraten
*/

void main()
   {
   int n, antwort;
   unsigned int zahl, bit;


   printf( " Anzahl Stellen: " );
   scanf( "%d", &n );
   printf( " Denk dir eine Zahl zwischen 0 und %d\n", ( 1 << n ) - 1 );

   for( zahl = 0, bit = ( 1 << n - 1 ); bit > 0; bit = ( bit >> 1 ) )
      {
      zahl = zahl | bit;
      printf( " Ist die Zahl kleiner als %d: ", zahl );
      scanf( "%d", &antwort );
      if( antwort == 1 )
         zahl = zahl & ~bit;
      }
   printf( " Die Zahl ist %d\n", zahl );
   }

