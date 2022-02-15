# include <stdlib.h>
# include <stdio.h>

/*
** Der Algorithmus von Floyd (Kap. 17.3.2.1)
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

# if 0

# define ANZAHL 5

static char *stadt[ANZAHL] =
   {
   "A",
   "B",
   "C",
   "D",
   "E"
   };

# define xxx 10000

static unsigned int distanz[ANZAHL][ANZAHL] =
   {
      { 0, 1, xxx, xxx, xxx },
      { xxx, 0, 2, xxx, xxx },
      { xxx, xxx, 0, 3, xxx },
      { 205, xxx, xxx, 0, 4 },
      { 5, xxx, xxx, xxx, 0 }
   };

# endif

int zwischenpunkt[ANZAHL][ANZAHL];

static void init()
   {
   int von, nach;

   for( von = 0; von < ANZAHL; von++ )
      {
      for( nach = 0; nach < ANZAHL; nach++ )
         zwischenpunkt[von][nach] = -1;
      }
   }

void print_nodes( int von, int nach )
   {
   int zpkt;

   zpkt = zwischenpunkt[von][nach];
   if( zpkt == -1 )
      return;
   print_nodes( von, zpkt );
   printf( "->%s", stadt[zpkt] );
   print_nodes( zpkt, nach );
   }

static void print_path( int von, int nach )
   {
   printf( "%s", stadt[von] );
   print_nodes( von, nach );
   printf( "->%s", stadt[nach] );
   printf( " (%d km)\n", distanz[von][nach] );
   }

void floyd()
   {
   int von, nach, zpkt;
   unsigned int d;

   for( zpkt = 0; zpkt < ANZAHL; zpkt++ )
      {
      for( von = 0; von < ANZAHL; von++ )
         {
         for( nach = 0; nach < ANZAHL; nach++ )
            {
            d = distanz[von][zpkt] + distanz[zpkt][nach];
            if( d < distanz[von][nach] )
               {
               distanz[von][nach] = d;
               zwischenpunkt[von][nach] = zpkt;
               }
            }
         }
      }
   }

void print_distanzen()
   {
   int z, s;

   printf( "Distanzen:\n" );
   for( z = 0; z < ANZAHL; z++ )
      {
      for( s = 0; s < ANZAHL; s++ )
         printf( "%3d ", distanz[z][s] );
      printf( "\n" );
      }
   printf( "\n" );
   }

void print_zwischenpunkte()
   {
   int z, s;

   printf( "Zwischenpunkte:\n" );
   for( z = 0; z < ANZAHL; z++ )
      {
      for( s = 0; s < ANZAHL; s++ )
         printf( "%3d ", zwischenpunkt[z][s] );
      printf( "\n" );
      }
   printf( "\n" );
   }

void main()
   {
   init();
   floyd();

   print_distanzen();
   print_zwischenpunkte();

   print_path( BERLIN, STUTTGART );
   print_path( MUENCHEN, HAMBURG );
   }
