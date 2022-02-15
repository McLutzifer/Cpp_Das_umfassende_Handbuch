# include <stdlib.h>
# include <stdio.h>

/*
** Ermittlung der Zusammenhangskomponenten durch Vereinigungssuche (Kap. 17.3.1.3)
*/


# define ANZ_KNOTEN 12
# define ANZ_KANTEN 17

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

static char *stadt[ANZ_KNOTEN] =
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



struct kante
   {
   int von;
   int nach;
   };

struct kante kantentabelle[ANZ_KANTEN] =
   {
      { 0, 3 },
      { 1, 6 },
      { 0, 7 },
      { 1, 7 },
      { 6, 7 },
      { 2, 8 },
      { 4, 8 },
      { 5, 8 },
      { 0, 9 },
      { 3, 9 },
      { 2, 4 },
      { 2, 5 },
      { 0, 6 },
      { 7, 9 },
      { 5, 10 },
      { 5, 11 },
      { 10, 11 }
   };

int vorgaenger[ANZ_KNOTEN];

void init()
   {
   int i;

   for( i = 0; i < ANZ_KNOTEN; i++ )
      vorgaenger[i] = -1;
   }

void join( int a, int b )
   {
   while( vorgaenger[a] != -1 )
      a = vorgaenger[a];
   while( vorgaenger[b] != -1 )
      b = vorgaenger[b];
   if( a != b )
      vorgaenger[b] = a;
   }

void bilde_komponenten()
   {
   int k;

   init();
   for( k = 0; k < ANZ_KANTEN; k++ )
      join( kantentabelle[k].von, kantentabelle[k].nach );
   }

int komponente( int a )
   {
   while( vorgaenger[a] != -1 )
      a = vorgaenger[a];
   return a;
   }

static void ausgabe()
   {
   int i, k, z;
   for( i = 0, z = 0; i < ANZ_KNOTEN; i++ )
      {
      if( vorgaenger[i] == -1 )
         {
         printf( "%d-te Zusammenhangskomponente:\n", ++z );
         for( k = 0; k < ANZ_KNOTEN; k++ )
            {
            if( komponente( k ) == i )
               printf( "    %2d %s\n", k, stadt[k] );
            }
         printf( "\n" );
         }
      }
   }

void main()
   {
   bilde_komponenten();
   ausgabe();
   }
