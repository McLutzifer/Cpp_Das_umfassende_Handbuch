# include <stdlib.h>
# include <stdio.h>

/*
** Approximative Loesung füer das Travelling Salesman Problem (Kap. 17.3.4)
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
      { 0, 412, 488, 205, 572, 555, 284, 282, 569, 179, 584, 634 },
      { 412, 0, 233, 470, 317, 466, 119, 125, 312, 362, 753, 640 },
      { 488, 233, 0, 607, 63, 264, 343, 208, 83, 532, 653, 451 },
      { 205, 470, 607, 0, 629, 469, 502, 364, 589, 108, 484, 524 },
      { 572, 317, 63, 629, 0, 232, 427, 292, 47, 558, 621, 419 },
      { 555, 466, 264, 469, 232, 0, 495, 352, 189, 395, 400, 217 },
      { 284, 119, 343, 502, 427, 495, 0, 154, 422, 391, 782, 668 },
      { 282, 125, 208, 364, 292, 352, 154, 0, 287, 256, 639, 526 },
      { 569, 312, 83, 589, 47, 189, 422, 287, 0, 515, 578, 376 },
      { 179, 362, 532, 108, 558, 395, 391, 256, 515, 0, 425, 465 },
      { 584, 753, 653, 484, 621, 400, 782, 639, 578, 425, 0, 220 },
      { 634, 640, 451, 524, 419, 217, 668, 526, 376, 465, 220, 0 },
   };


static int spannbaum[ANZAHL][ANZAHL] =
   {
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
      { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1 },
      { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
      { 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
      { 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
      { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0 },
   };

static int pfad[ANZAHL];
int position;

void tiefensuche( int knoten, int herkunft )
   {
   int i;

   pfad[position++] = knoten;
   for( i = 0; i < ANZAHL; i++ )
      {
      if( spannbaum[knoten][i] && ( herkunft != i ) )
         tiefensuche( i, knoten );
      }

   }

static void ausgabe()
   {
   int i;
   int d;

   for( i = 0, d = 0; i < ANZAHL; i++ )
      {
      printf( "%d-", pfad[i] );
      d += distanz[pfad[i]][pfad[( i + 1 ) % ANZAHL]];
      }
   printf( "%d (%d km)\n", pfad[0], d );
   }

void main()
   {
   int start;

   for( start = 0; start < ANZAHL; start++ )
      {
      position = 0;
      tiefensuche( start, -1 );
      ausgabe();
      }
   }
