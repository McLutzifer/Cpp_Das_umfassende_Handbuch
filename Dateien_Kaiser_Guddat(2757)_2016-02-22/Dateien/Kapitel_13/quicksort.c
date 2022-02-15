# include <stdio.h>
# include <stdlib.h>
# include <math.h>

/*
** Quicksort (Kap. 13.5)
*/

static int aufteilung( int links, int rechts, int *daten )
   {
   int pivot, i, j, t;

   pivot = daten[rechts];
   i = links - 1;
   j = rechts;

   for( ;; )
      {
      while( daten[++i] < pivot )
         ;
      while( ( j > i ) && ( daten[--j] > pivot ) )
         ;
      if( i >= j )
         break;
      t = daten[i];
      daten[i] = daten[j];
      daten[j] = t;
      }
   daten[rechts] = daten[i];
   daten[i] = pivot;
   return i;
   }

void qcksort1( int links, int rechts, int *daten )
   {
   int i;

   if( links < rechts )
      {
      i = aufteilung( links, rechts, daten );
      qcksort1( links, i - 1, daten );
      qcksort1( i + 1, rechts, daten );
      }
   }



void qcksort( int links, int rechts, int *daten )
   {
   int pivot, i, j, t;

   if( links < rechts )
      {
      i = links - 1;
      j = rechts;
      pivot = daten[rechts];
      for( ;; )
         {
         while( daten[++i] < pivot )
            ;
         while( ( j > i ) && ( daten[--j] > pivot ) )
            ;
         if( i >= j )
            break;
         t = daten[i];
         daten[i] = daten[j];
         daten[j] = t;
         }
      daten[rechts] = daten[i];
      daten[i] = pivot;

      qcksort( links, i - 1, daten );
      qcksort( i + 1, rechts, daten );
      }
   }


void quicksort( int n, int *daten )
   {
   qcksort( 0, n - 1, daten );
   }


/*
** Iteratives Quicksort
*/

void qsortiter1( int links, int rechts, int *daten )
   {
   int i;
   int stack[256];
   int pos = 0;

   stack[pos++] = links;
   stack[pos++] = rechts;
   while( pos )
      {
      rechts = stack[--pos];
      links = stack[--pos];
      if( links < rechts )
         {
         i = aufteilung( links, rechts, daten );
         stack[pos++] = links;
         stack[pos++] = i - 1;
         stack[pos++] = i + 1;
         stack[pos++] = rechts;
         }
      }
   }



void qsortiter( int n, int *daten )
   {
   int pivot, i, j, t;
   int links, rechts;
   int stack[256];
   int pos = 0;

   stack[pos++] = 0;
   stack[pos++] = n - 1;

   while( pos )
      {
      rechts = stack[--pos];
      links = stack[--pos];

      if( links < rechts )
         {
         i = links - 1;
         j = rechts;
         pivot = daten[rechts];
         for( ;; )
            {
            while( daten[++i] < pivot )
               ;
            while( ( j > i ) && ( daten[--j] > pivot ) )
               ;
            if( i >= j )
               break;
            t = daten[i];
            daten[i] = daten[j];
            daten[j] = t;
            }
         daten[rechts] = daten[i];
         daten[i] = pivot;

         stack[pos++] = links;
         stack[pos++] = i - 1;
         stack[pos++] = i + 1;
         stack[pos++] = rechts;
         }
      }
   }






/*
** Testrahmen
*/


static void testdaten( int n, int *daten )
   {
   int i;

   for( i = 0; i < n; i++ )
      daten[i] = rand() % n;
   }

static int pruefen( int n, int *daten )
   {
   int i;

   for( i = 0; i < n - 1; i++ )
      {
      if( daten[i] > daten[i + 1] )
         return 0;
      }
   return 1;
   }

# define ANZAHL 100

void main()
   {
   int daten[ANZAHL];

   srand( 4711 );
   testdaten( ANZAHL, daten );
   quicksort( ANZAHL, daten );
   if( pruefen( ANZAHL, daten ) )
      printf( "ok\n" );
   else
      printf( "nicht ok\n" );
   }
