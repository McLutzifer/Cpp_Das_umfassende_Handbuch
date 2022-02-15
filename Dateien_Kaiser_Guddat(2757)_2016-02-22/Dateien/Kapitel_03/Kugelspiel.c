# include <stdio.h>
# include <stdlib.h>

/*
** Das zweite C-Programm (Kap. 3.9.2)
*/

void main()
   {
   int weiche1, weiche2, weiche3, weiche4;
   char position;
   int kugeln;

   printf( "  Bitte geben Sie die Weichenstellungen ein: " );
   scanf( "%d %d %d %d", &weiche1, &weiche2, &weiche3, &weiche4 );
   printf( "  Bitte geben Sie die Anzahl der Kugeln ein: " );
   scanf( "%d", &kugeln );

   for( ; kugeln > 0; kugeln = kugeln - 1 )
      {
      if( weiche1 == 1 )
         position = 1;
      else
         position = 2;
      weiche1 = 1 - weiche1;
      if( position == 1 )
         {
         if( weiche2 == 1 )
            position = 4;
         else
            position = 3;
         weiche2 = 1 - weiche2;
         }
      else
         {
         if( weiche3 == 1 )
            position = 3;
         else
            position = 5;
         weiche3 = 1 - weiche3;
         }
      if( position == 3 )
         {
         if( weiche4 == 1 )
            position = 4;
         else
            position = 5;
         weiche4 = 1 - weiche4;
         }
      printf( "  Auslauf: %d, ", position );
      printf( "neue Weichenstellung %d %d %d %d\n", weiche1, weiche2, weiche3, weiche4 );
      }
   }



