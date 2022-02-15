# include <stdlib.h>
# include <stdio.h>

/*
** Traversierung von Graphen (Kap 17.3.1.1)
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

unsigned int adjazenz[ANZAHL][ANZAHL] =
   {
      { 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0 },
      { 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
      { 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0 },
      { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
      { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
      { 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
      { 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
      { 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0 },
      { 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
      { 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0 },
      { 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
      { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0 },
   };


void machwas( int knoten, int level )
   {
   int i;

   for( i = 0; i < level; i++ )
      printf( "  " );
   printf( "%s\n", stadt[knoten] );
   }

void traverse( int knoten, int war_schon_da[], int level )
   {
   int i;

   machwas( knoten, level );
   war_schon_da[knoten] = 1;
   for( i = 0; i < ANZAHL; i++ )
      {
      if( adjazenz[knoten][i] && !war_schon_da[i] )
         traverse( i, war_schon_da, level + 1 );
      }
   }

void main()
   {
   int i;
   int war_da[ANZAHL];

   for( i = 0; i < ANZAHL; i++ )
      war_da[i] = 0;
   traverse( BERLIN, war_da, 0 );
   }
