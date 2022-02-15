# include <stdio.h>
# include <stdlib.h>

/*
** Sudoku
*/

void main()
   {
   int sudoku[9][9] = {
      { 5, 0, 9, 7, 0, 2, 0, 4, 0 },
      { 7, 6, 0, 3, 4, 8, 9, 1, 5 },
      { 1, 3, 4, 5, 0, 9, 0, 7, 0 },
      { 6, 7, 1, 0, 0, 0, 0, 0, 0 },
      { 8, 0, 5, 6, 2, 1, 7, 3, 4 },
      { 0, 0, 3, 0, 5, 0, 1, 6, 9 },
      { 0, 5, 8, 1, 0, 0, 3, 2, 7 },
      { 3, 0, 0, 2, 0, 0, 0, 9, 6 },
      { 9, 0, 0, 0, 7, 3, 8, 5, 0 },
      };
   int zeile, spalte, zahl;

   for( zahl = 1; zahl != 0; )
      {
      printf( "\n" );
      for( zeile = 0; zeile < 9; zeile++ )
         {
         if( zeile % 3 == 0 )
            printf( "+-------+-------+-------+\n" );
         for( spalte = 0; spalte < 9; spalte++ )
            {
            if( spalte % 3 == 0 )
               printf( "| " );
            if( sudoku[zeile][spalte] > 0 )
               printf( "%d ", sudoku[zeile][spalte] );
            else
               printf( "  " );
            }
         printf( "|\n" );
         }
      printf( "+-------+-------+-------+\n" );
      printf( "Zeile Spalte Zahl: " );
      scanf( "%d %d %d", &zeile, &spalte, &zahl );
      sudoku[zeile][spalte] = zahl;
      }
   }

