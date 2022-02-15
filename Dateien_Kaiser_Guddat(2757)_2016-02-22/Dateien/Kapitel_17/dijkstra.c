# include <stdlib.h>
# include <stdio.h>

/*
** Der Algorithmus von Dijkstra (Kap 17.3.2.2)
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

static unsigned int distanz[ANZAHL][ANZAHL] =
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
   char erledigt;
   };

struct knoteninfo info[ANZAHL];

static void print_path( int i )
   {
   if( info[i].vorgaenger != -1 )
      print_path( info[i].vorgaenger );
   printf( "%s-", stadt[i] );
   }

static void print_all()
   {
   int i;

   for( i = 0; i < ANZAHL; i++ )
      {
      print_path( i );
      printf( "%dkm\n", info[i].distanz );
      }
   }

static void init( int ausgangspkt )
   {
   int i;

   for( i = 0; i < ANZAHL; i++ )
      {
      info[i].erledigt = 0;
      info[i].distanz = distanz[ausgangspkt][i];
      info[i].vorgaenger = ausgangspkt;
      }
   info[ausgangspkt].erledigt = 1;
   info[ausgangspkt].vorgaenger = -1;
   }

int knoten_auswahl()
   {
   int i, minpos;
   unsigned int min;

   min = xxx;
   minpos = -1;
   for( i = 0; i < ANZAHL; i++ )
      {
      if( info[i].distanz < min && !info[i].erledigt )
         {
         min = info[i].distanz;
         minpos = i;
         }
      }
   return minpos;
   }

void dijkstra( int ausgangspkt )
   {
   int i, knoten, k;
   unsigned int d;

   init( ausgangspkt );
   for( i = 0; i < ANZAHL - 2; i++ )
      {
      knoten = knoten_auswahl();
      info[knoten].erledigt = 1;
      for( k = 0; k < ANZAHL; k++ )
         {
         if( info[k].erledigt )
            continue;
         d = info[knoten].distanz + distanz[knoten][k];
         if( d < info[k].distanz )
            {
            info[k].distanz = d;
            info[k].vorgaenger = knoten;
            }
         }
      }
   }

void main()
   {
   dijkstra( BERLIN );
   print_all();
   }
