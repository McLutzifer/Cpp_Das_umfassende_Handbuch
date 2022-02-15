# include <stdio.h>
# include <stdlib.h>

/*
** Palindrom
*/

void main()
   {
   char wort[100];
   int vorn, hinten;

   printf( "Wort: " );
   scanf( "%s", wort );

   for( hinten = 0; wort[hinten] != 0; hinten++ )
      ;

   for( vorn = 0, hinten--; vorn < hinten; vorn++, hinten-- )
      {
      if( wort[vorn] != wort[hinten] )
         break;
      }

   if( vorn < hinten )
      printf( "Kein Palindrom\n" );
   else
      printf( "Palindrom\n" );
   }

