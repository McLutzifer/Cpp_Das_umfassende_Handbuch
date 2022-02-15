# include <stdio.h>
# include <stdlib.h>

/*
** Addierwerk
*/
void main()
   {
   unsigned int z1, z2;
   unsigned int s1, s2, s, sum, c;

   printf( " Gib bitte zwei Zahlen ein: " );
   scanf( "%d %d", &z1, &z2 );

   for( sum = 0, s = 1, c = 0; s != 0; s = s << 1, c = c << 1 )
      {
      s1 = z1 & s;
      s2 = z2 & s;
      sum = sum | ( s1 ^ s2 ^ c );
      c = ( s1 & s2 ) | ( s1 & c ) | ( s2 & c );
      }
   printf( " Summe: %d\n", sum );
   }
