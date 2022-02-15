# include <stdio.h>
# include <stdlib.h>

/*
** Tuerme von Hanoi
*/


void hanoi( int n, char start, char tmp, char ziel )
   {
   if( n > 1 )
      {
      hanoi( n - 1, start, ziel, tmp );
      printf( "Ring %d: %c -> %c\n", n, start, ziel );
      hanoi( n - 1, tmp, start, ziel );
      }
   else
      printf( "Ring %d: %c -> %c\n", n, start, ziel );
   }

void main()
   {
   hanoi( 5, 'S', 'T', 'Z' );
   }

