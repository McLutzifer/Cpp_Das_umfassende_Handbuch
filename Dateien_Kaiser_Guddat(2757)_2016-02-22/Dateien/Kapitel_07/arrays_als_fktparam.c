#include <stdio.h>

void init( int anz, int dat[] )
   {
   int i;

   for (i = 0; i < anz; i++)
      dat[i] = 2 * i;
   }


void ausgeben( int anz, int dat[] )
   {
   int i;

   for (i = 0; i < anz; i++)
      printf( "%d ", dat[i] );
   printf( "\n" );
   }


void umkehren( int anz, int dat[] )
   {
   int v, h, t;

   for (v = 0, h = anz - 1; v < h; v++, h--)
      {
      t      = dat[v];
      dat[v] = dat[h];
      dat[h] = t;
      }
   }


void main()
   {
   int daten[10];

   init( 10, daten );
   ausgeben( 10, daten );
   umkehren( 10, daten );
   ausgeben( 10, daten );
   }
