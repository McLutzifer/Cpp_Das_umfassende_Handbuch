
#include <stdio.h>

void init( int anz, int dat[])
{
   int i;
   for ( i = 0; i < anz; i++)
      dat[i] = 2 * i;
}

void ausgeben ( int anz, int dat[])
{
   int i;
   for ( i = 0; i < anz; i++)
      printf ( "%d ", dat[i]);

   printf ( "\n");
}

void umkehren ( int anz, int dat[])
{
   int v, h, t;

   /* Die Schleife arbeitet sich gleichzeitig von
   vorne und hinten durch den Text und verwendet dafür die
   Variablen v und h die zuerst auf ihre Startwerte gesetzt werden.
   Solange die Mitte noch nicht erreicht ist (v < h)
   werden jeweils v inkrementiert und h dekrementiert
   */
   for (v = 0, h = anz - 1; v < h; v++, h--)
   {
      /* Vertauschen der Werte an den Positionen v und h */
      t = dat[v];
      dat[v] = dat[h];
      dat[h] = t;
   }
}


int main()
{
   int daten[10];
   init ( 10, daten);
   ausgeben ( 10, daten);
   umkehren ( 10, daten);
   ausgeben ( 10, daten);
}
