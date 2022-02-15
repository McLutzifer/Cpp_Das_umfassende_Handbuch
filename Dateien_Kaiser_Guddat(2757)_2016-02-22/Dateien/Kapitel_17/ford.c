# include <stdlib.h>
# include <stdio.h>

/*
** Der Algorithmus von Ford (Kap. 17.3.2.3)
*/

# define ANZAHL 12

# define BERLIN       0
# define BREMEN       1
# define DORTMUND     2
# define DRESDEN      3
# define DUESSELDORF  4
# define FRANKFURT    5
# define HAMBURG      6
# define HANNOVER     7
# define KOELN        8
# define LEIPZIG      9
# define MUENCHEN    10
# define STUTTGART   11

static char *stadt[ANZAHL] =
   {
   "Berlin",
   "Bremen",
   "Dortmund",
   "Dresden",
   "Duesseldorf",
   "Frankfurt",
   "Hamburg",
   "Hannover",
   "Koeln",
   "Leipzig",
   "Muenchen",
   "Stuttgart"
   };

# define xxx 10000

static int distanz[ANZAHL][ANZAHL] =
   {
      { 0, xxx, xxx, 205, xxx, xxx, 284, 282, xxx, 179, xxx, xxx },
      { xxx, 0, 233, xxx, xxx, xxx, 119, 125, xxx, xxx, xxx, xxx },
      { xxx, 233, 0, xxx, 63, 264, xxx, 208, 83, xxx, xxx, xxx },
      { 205, xxx, xxx, 0, xxx, xxx, xxx, xxx, xxx, 108, xxx, xxx },
      { xxx, xxx, 63, xxx, 0, xxx, xxx, xxx, 47, xxx, xxx, xxx },
      { xxx, xxx, 264, xxx, xxx, 0, xxx, 352, 189, 395, 400, 217 },
      { 284, 119, xxx, xxx, xxx, xxx, 0, 154, xxx, xxx, xxx, xxx },
      { 282, 125, 208, xxx, xxx, 352, 154, 0, xxx, 256, xxx, xxx },
      { xxx, xxx, 83, xxx, 47, 189, xxx, xxx, 0, xxx, xxx, xxx },
      { 179, xxx, xxx, 108, xxx, 395, xxx, 256, xxx, 0, 425, xxx },
      { xxx, xxx, xxx, xxx, xxx, 400, xxx, xxx, xxx, 425, 0, 220 },
      { xxx, xxx, xxx, xxx, xxx, 217, xxx, xxx, xxx, xxx, 220, 0 },
   };




struct knoteninfo
   {
   unsigned int distanz;
   int vorgaenger;
   };

struct knoteninfo info[ANZAHL];

static void init( int ausgangspkt )
   {
   int i;

   for( i = 0; i < ANZAHL; i++ )
      {
      info[i].distanz = xxx;
      info[i].vorgaenger = ausgangspkt;
      }
   info[ausgangspkt].distanz = 0;
   info[ausgangspkt].vorgaenger = -1;
   }

# if 0

void ford_adjazenz( int ausgangspkt )
   {
   int von, nach;
   unsigned int d;
   int stop;

   init( ausgangspkt );
   for( stop = 0; !stop; )
      {
      stop = 1;
      for( von = 0; von < ANZAHL; von++ )
         {
         for( nach = 0; nach < ANZAHL; nach++ )
            {
            d = info[von].distanz + distanz[von][nach];
            if( d < info[nach].distanz )
               {
               info[nach].distanz = d;
               info[nach].vorgaenger = von;
               stop = 0;
               }
            }
         }
      }

# endif

   void print_path( int i )
      {
      if( info[i].vorgaenger != -1 )
         print_path( info[i].vorgaenger );
      printf( "%s-", stadt[i] );
      }

   void print_all()
      {
      int i;

      for( i = 0; i < ANZAHL; i++ )
         {
         print_path( i );
         printf( "%d km\n", info[i].distanz );
         }
      }

   struct kante
      {
      int von;
      int nach;
      int distanz;
      };

   int anzahl_kanten;
   struct kante kantentabelle[ANZAHL*ANZAHL];


   void setup_kantentabelle()
      {
      int i, j, k, d;

      for( i = k = 0; i < ANZAHL; i++ )
         {
         for( j = 0; j < ANZAHL; j++ )
            {
            d = distanz[i][j];
            if( ( d > 0 ) && ( d < xxx ) )
               {
               kantentabelle[k].distanz = d;
               kantentabelle[k].von = i;
               kantentabelle[k].nach = j;
               k++;
               }
            }
         anzahl_kanten = k;
         }
      }

   void print_kantentabelle()
      {
      int i;

      for( i = 0; i < anzahl_kanten; i++ )
         printf( "Kante %2d: %s->%s %d\n", i + 1, stadt[kantentabelle[i].von], stadt[kantentabelle[i].nach], kantentabelle[i].distanz );
      }



   void ford( int ausgangspkt )
      {
      int von, nach;
      unsigned int d;
      int stop;
      int kante;

      init( ausgangspkt );
      for( stop = 0; !stop; )
         {
         stop = 1;
         for( kante = 0; kante < anzahl_kanten; kante++ )
            {
            von = kantentabelle[kante].von;
            nach = kantentabelle[kante].nach;
            d = info[von].distanz + kantentabelle[kante].distanz;
            if( d < info[nach].distanz )
               {
               info[nach].distanz = d;
               info[nach].vorgaenger = von;
               stop = 0;
               }
            }
         }
      }

   void main()
      {
      setup_kantentabelle();
      print_kantentabelle();
      ford( BERLIN );
      print_all();
      }
