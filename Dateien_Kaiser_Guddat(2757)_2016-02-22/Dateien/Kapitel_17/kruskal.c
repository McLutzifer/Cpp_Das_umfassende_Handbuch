# include <stdlib.h>
# include <stdio.h>

/*
** Der Algorithmus von Kruskal zur Berechnung eines minimalen Spannbaums (Kap. 17_3_3)
*/


# define ANZAHL 12
# define ANZ_KANTEN 22

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

char *stadt[ANZAHL] =
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

int vorgaenger[ANZAHL];
int ausgewaehlt[ANZ_KANTEN];

struct kante
   {
   int distanz;
   int von;
   int nach;
   };

static struct kante kantentabelle[ANZ_KANTEN] =
   {
      { 47, 4, 8 },
      { 63, 2, 4 },
      { 83, 2, 8 },
      { 108, 3, 9 },
      { 119, 1, 6 },
      { 125, 1, 7 },
      { 154, 6, 7 },
      { 179, 0, 9 },
      { 189, 5, 8 },
      { 205, 0, 3 },
      { 208, 2, 7 },
      { 217, 5, 11 },
      { 220, 10, 11 },
      { 233, 1, 2 },
      { 256, 7, 9 },
      { 264, 2, 5 },
      { 282, 0, 7 },
      { 284, 0, 6 },
      { 352, 5, 7 },
      { 395, 5, 9 },
      { 400, 5, 10 },
      { 425, 9, 10 },
   };

static void init()
   {
   int i;

   for( i = 0; i < ANZAHL; i++ )
      vorgaenger[i] = -1;
   }

static int join( int a, int b )
   {
   while( vorgaenger[a] != -1 )
      a = vorgaenger[a];
   while( vorgaenger[b] != -1 )
      b = vorgaenger[b];
   if( a == b )
      return 0;
   vorgaenger[b] = a;
   return 1;
   }

void kruskal()
   {
   int kante;

   init();
   for( kante = 0; kante < ANZ_KANTEN; kante++ )
      ausgewaehlt[kante] = join( kantentabelle[kante].von, kantentabelle[kante].nach );
   }

static void ausgabe()
   {
   int kante;
   unsigned int summe;

   for( kante = 0, summe = 0; kante < ANZ_KANTEN; kante++ )
      {
      if( ausgewaehlt[kante] )
         {
         summe += kantentabelle[kante].distanz;
         printf( "%4d %s-%s\n", kantentabelle[kante].distanz, stadt[kantentabelle[kante].von],
                 stadt[kantentabelle[kante].nach] );
         }
      }
   printf( "----\n%4d\n", summe );
   }

void main()
   {
   kruskal();
   ausgabe();
   }
