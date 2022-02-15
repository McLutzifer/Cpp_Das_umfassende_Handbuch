# include <stdio.h>
# include <stdlib.h>

/*
** Zahlentrick
*/

void main()
   {
   int bit, z, zahl, antwort;

   printf( " Denk dir eine Zahl zwischen 0 und 31\n" );
   for( bit = 1, zahl = 0; bit < 32; bit = bit << 1 )
      {
      printf( " Ist die Zahl in dieser Liste" );
      for( z = 0; z < 32; z++ )
         {
         if( z & bit )
            printf( " %d", z );
         }
      printf( ": " );
      scanf( "%d", &antwort );
      if( antwort == 1 )
         zahl |= bit;
      }
   printf( " Die Zahl ist %d\n", zahl );
   }

