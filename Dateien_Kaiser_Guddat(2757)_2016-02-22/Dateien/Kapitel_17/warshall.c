# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

/*
** Das Verfahren von Warshall (Kap. 17.3.1.2)
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

static unsigned int weg[ANZAHL][ANZAHL] =
   {
      { 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0 },
      { 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
      { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
   };

void warshall()
   {
   int  von, nach, zpkt;

   for( zpkt = 0; zpkt < ANZAHL; zpkt++ )
      {
      for( von = 0; von < ANZAHL; von++ )
         {
         if( weg[von][zpkt] )
            {
            for( nach = 0; nach < ANZAHL; nach++ )
               {
               if( weg[zpkt][nach] )
                  weg[von][nach] = 1;
               }
            }
         }
      }
   }

static void ausgabe()
   {
   int i, j;

   printf( "   " );
   for( i = 0; i < ANZAHL; i++ )
      printf( " %.3s", stadt[i] );
   printf( "\n", stadt[i] );

   for( i = 0; i < ANZAHL; i++ )
      {
      printf( "%.3s ", stadt[i] );
      for( j = 0; j < ANZAHL; j++ )
         printf( " %d  ", weg[i][j] );
      printf( "\n" );
      }

   }

void main()
   {
   warshall();
   ausgabe();
   }
