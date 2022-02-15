# include <stdio.h>
# include <stdlib.h>

/*
** Tilgungsplan (Kap. 4.1)
*/

void main()
   {
   float rest, rate, zins1, zins2, sondertilgung;
   int bindung;

   int monat;
   float zins, zinsen, tilgung, sonderz;

   printf( "  Darlehen:                 " );
   scanf( "%f", &rest );
   printf( "  Nominalzins:              " );
   scanf( "%f", &zins1 );
   printf( "  Monatsrate:               " );
   scanf( "%f", &rate );
   printf( "  Zinsbindung (Jahre):      " );
   scanf( "%d", &bindung );
   printf( "  Zinssatz nach Bindung:    " );
   scanf( "%f", &zins2 );
   printf( "  Jaehrliche Sondertilgung: " );
   scanf( "%f", &sondertilgung );

   printf( "\n  Tilgungsplan:\n\n" );
   printf( "  Monat   Zinssatz     Zinsen    Tilgung Sondertilg Rest\n" );

   for( monat = 1; rest > 0; monat = monat + 1 )
      {
      printf( "  %5d", monat );
      if( monat <= bindung * 12 )
         zins = zins1;
      else
         zins = zins2;
      printf( " %10.2f", zins );
      zinsen = rest * zins / 1200;
      printf( " %10.2f", zinsen );
      tilgung = rate - zinsen;
      if( tilgung > rest )
         tilgung = rest;
      printf( " %10.2f", tilgung );
      rest = rest - tilgung;
      sonderz = 0;
      if( ( monat % 12 ) == 0 )
         {
         sonderz = sondertilgung;
         if( sonderz > rest )
            sonderz = rest;
         }
      printf( " %10.2f", sonderz );
      rest = rest - sonderz;
      printf( " %10.2f", rest );
      printf( "\n" );
      }
   }

