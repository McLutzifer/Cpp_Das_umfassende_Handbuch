# include <stdio.h>
# include <stdlib.h>

/*
** 4-Damenproblem
*/

static int abstand( int x, int y )
   {
   if( x >= y )
      return x - y;
   return y - x;
   }


static int schlagen( int x, int y, int damen[] )
   {
   int dh, dv;

   dv = abstand( x, y );
   dh = abstand( damen[x], damen[y] );
   if( ( dh == 0 ) || ( dv == dh ) )
      return 1;
   return 0;
   }

static int stellung_ok( int x, int damen[] )
   {
   int i;

   for( i = 0; i < x; i = i + 1 )
      {
      if( schlagen( i, x, damen ) )
         return 0;
      }
   return 1;
   }

static int laufendenummer = 0;

static void print_loesung( int anz, int damen[] )
   {
   int i;

   laufendenummer++;
   printf( "%2d. Loesung: ", laufendenummer );
   for( i = 0; i < anz; i = i + 1 )
      printf( " %d", damen[i] );
   printf( "\n" );
   }



static void damenproblem( int anz, int damen[], int lvl )
   {
   if( lvl == anz )
      {
      print_loesung( anz, damen );
      return;
      }
   for( damen[lvl] = 1; damen[lvl] <= anz; damen[lvl]++ )
      {
      if( stellung_ok( lvl, damen ) )
         damenproblem( anz, damen, lvl + 1 );
      }
   }

void main()
   {
   int damen[20];
   int anz;

   printf( "Anzahl: " );
   scanf( "%d", &anz );

   damenproblem( anz, damen, 0 );
   }


