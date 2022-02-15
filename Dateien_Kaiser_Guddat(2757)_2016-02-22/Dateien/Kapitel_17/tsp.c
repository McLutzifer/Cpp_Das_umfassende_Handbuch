# include <stdlib.h>
# include <stdio.h>

/*
** Hamiltonsche Wege im deutschen Autobahnnetz (Kap 17.3.4)
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

int mindist = xxx;
int minpfad[ANZAHL];

# if 0
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


# endif
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


int zaehler = 0;

static void hamilton( int anz, int array[], int start )
   {
   int i, sav;
   unsigned int d;

   if( start == anz )
      {
      if( distanz[array[anz - 1]][array[0]] < xxx )
         {
         zaehler++;
         if( zaehler == 0 )
            printf( "ssss\n" );
         for( i = 0, d = 0; i < anz; i++ )
            d += distanz[array[i]][array[( i + 1 ) % anz]];
         if( d < mindist )
            {
            mindist = d;
            for( i = 0, d = 0; i < anz; i++ )
               minpfad[i] = array[i];
            }
         }
      }
   else
      {
      sav = array[start];
      for( i = start; i < anz; i++ )
         {
         array[start] = array[i];
         array[i] = sav;
         if( distanz[array[start - 1]][array[start]] < xxx )
            hamilton( anz, array, start + 1 );
         array[i] = array[start];
         }
      array[start] = sav;
      }
   }

void main()
   {
   int pfad[ANZAHL];
   int i;

   for( i = 0; i < ANZAHL; i++ )
      pfad[i] = i;

   hamilton( 12, pfad, 1 );

   for( i = 1; i <= ANZAHL; i++ )
      printf( "%5d %s-%s\n", distanz[minpfad[i - 1]][minpfad[i%ANZAHL]], stadt[minpfad[i - 1]], stadt[minpfad[i%ANZAHL]] );
   printf( "%5d\n", mindist );
   printf( "%d Hamiltonsche Wege untersucht\n", zaehler );
   }
