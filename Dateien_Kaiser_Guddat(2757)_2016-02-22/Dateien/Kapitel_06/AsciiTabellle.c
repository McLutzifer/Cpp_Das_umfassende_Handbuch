# include <stdio.h>
# include <stdlib.h>

/*
** ASCII-Tabelle
*/


void main()
   {
   unsigned char zeile, spalte, z;

   printf( "    " );
   for( spalte = 0; spalte < 0x10; spalte++ )
      printf( " .%x", spalte );
   printf( "\n" );
   for( zeile = 0; zeile < 0x08; zeile++ )
      {
      printf( "  %x.", zeile );
      for( spalte = 0; spalte < 0x10; spalte++ )
         {
         z = ( zeile << 4 ) | spalte;
         if( ( z > 0x20 ) && ( z < 0x7f ) )
            printf( "  %c", z );
         else
            printf( "  ." );
         }
      printf( "\n" );
      }
   }

