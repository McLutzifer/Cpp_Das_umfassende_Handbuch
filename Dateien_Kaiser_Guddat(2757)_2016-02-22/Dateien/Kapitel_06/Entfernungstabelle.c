# include <stdio.h>
# include <stdlib.h>

/*
** Entfernungstabelle
*/

void main()
   {
   int start, ziel, distanz;
   int entfernung[5][5] = {
      { 0, 2, 5, 9, 14 },
      { 2, 0, 7, 15, 27 },
      { 5, 7, 0, 9, 23 },
      { 9, 15, 9, 0, 12 },
      { 14, 27, 23, 12, 0 }
      };

   printf( "Gib zwei Orte (0-4) ein: " );
   scanf( "%d %d", &start, &ziel );

   distanz = entfernung[start][ziel];

   printf( "Entfernung zwischen %d und %d: %d km\n", start, ziel, distanz );
   }

