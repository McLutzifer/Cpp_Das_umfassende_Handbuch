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

static void damen4()
   {
   int damen[4];

   for( damen[0] = 1; damen[0] <= 4; damen[0]++ )
      {
      for( damen[1] = 1; damen[1] <= 4; damen[1]++ )
         {
         if( !stellung_ok( 1, damen ) )
            continue;
         for( damen[2] = 1; damen[2] <= 4; damen[2]++ )
            {
            if( !stellung_ok( 2, damen ) )
               continue;
            for( damen[3] = 1; damen[3] <= 4; damen[3]++ )
               {
               if( stellung_ok( 3, damen ) )
                  print_loesung( 4, damen );
               }
            }
         }
      }
   }

void main()
   {
   laufendenummer = 0;
   damen4();
   }

