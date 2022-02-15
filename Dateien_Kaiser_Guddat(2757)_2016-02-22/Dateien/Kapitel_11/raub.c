# include <stdio.h>
# include <stdlib.h>
# include <math.h>

/*
** Juwelenraub (Kap. 10.3.1)
*/


double beute[10] = { 333.33, 655.99, 387.50, 1420.10, 4583.17,
7500.00, 215.12, 3230.17, 599.00, 3775.11 };

double summe;

int anzahl;
int auswahl[10];
double teilsumme;
double abweichung;

void vorbereitung()
   {
   int i;

   for( i = 0, summe = 0.0; i < 10; i++ )
      {
      printf( "Beutestueck %2d: %10.2f Euro\n", i + 1, beute[i] );
      summe += beute[i];
      }
   printf( "Gesamtbeute:    %10.2f Euro\n\n", summe );
   abweichung = summe + 1;
   }

void aufteilung( int k, int array[] )
   {
   int i;
   double teil;
   double abw;

   for( i = 0, teil = 0.0; i < k; i++ )
      teil += beute[array[i]];

   abw = fabs( summe / 2 - teil );

   if( abw < abweichung )
      {
      abweichung = abw;
      teilsumme = teil;
      anzahl = k;
      for( i = 0; i < k; i++ )
         auswahl[i] = array[i];
      }
   }

static void komb_ow( int n, int k, int array[], int x, int min )
   {
   int i;

   if( x < k )
      {
      for( i = min; i <= n - k + x; i++ )
         {
         array[x] = i;
         komb_ow( n, k, array, x + 1, i + 1 );
         }
      }
   else
      aufteilung( k, array );
   }


void auswertung()
   {
   int i;

   printf( "Der Komplize erhaelt:\n\n" );
   for( i = 0; i < anzahl; i++ )
      {
      printf( "    Beutestueck %2d %10.2f Euro\n", auswahl[i] + 1,
              beute[auswahl[i]] );
      }
   printf( "\nTeilsumme          %10.2f Euro\n", teilsumme );
   printf( "\nAbweichung         %10.2f Euro\n", abweichung );
   }

void main()
   {
   int array[5];
   int i;

   vorbereitung();
   for( i = 1; i <= 5; i++ )
      komb_ow( 10, i, array, 0, 0 );
   auswertung();
   }



