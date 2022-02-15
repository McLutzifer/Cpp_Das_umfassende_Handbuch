# include <stdio.h>
# include <stdlib.h>

/*
** n-Damenproblem (Kap. 7.6.1.2)
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

static unsigned long long stellungen = 0;


static int stellung_ok( int x, int damen[] )
   {
   int i;

   stellungen++;
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


static void damenproblem( int anz, int damen[] )
   {
   int lvl;

   for( lvl = 0, damen[lvl] = 0; lvl >= 0; )
      {
      damen[lvl]++;
      if( damen[lvl] <= anz )
         {
         if( stellung_ok( lvl, damen ) )
            {
            if( lvl == anz - 1 )
               print_loesung( anz, damen );
            else
               {
               lvl++;
               damen[lvl] = 0;
               }
            }
         }
      else
         lvl--;
      }
   }


//static void damenproblem( int anz, int damen[])
//        {
//        int lvl;
//
//        for( lvl = 0, damen[lvl] = 0; lvl >= 0;)
//            {
//            damen[lvl]++;
//            if( damen[lvl] <= anz)
//                {
//                if( stellung_ok( lvl, damen))
//                    {
//                    if( lvl == anz - 1)
//                        print_loesung( anz, damen);
//                    else
//                        {
//                        lvl++;
//                        damen[lvl] = 0;
//                        }
//                    }
//                }
//            else
//                lvl--;
//            }
//        }


//void main()
//    {
//    int damen[20];
//    int anz;
//
//    for( anz = 1; anz <= 12; anz++)
//        {
//        printf( "\n%d Damenproblem\n", anz);
//        laufendenummer = 0;
//        damenproblem( anz, 0, damen);
//        }
//    }

void main()
   {
   int damen[20];
   int anz;
   int i;

   damenproblem( 4, damen );
   //printf( "Damen Loesungen      Stellungen\n");
   //for( anz = 1; anz <= 4; anz++)
   //    {
   //    laufendenummer = 0;
   //    stellungen = 0;
   //    damenproblem( anz, damen);
   //    printf( "%5d %9d %15lld\n", anz, laufendenummer, stellungen);
   //    }
   }