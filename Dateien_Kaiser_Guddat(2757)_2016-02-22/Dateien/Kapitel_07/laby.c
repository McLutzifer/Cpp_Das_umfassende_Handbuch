# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/*
** Labyrinth
*/

char labyrinth[22][22] =
   {
   "#####################",
   "# #             #   #",
   "# # ############# # #",
   "# #        #      # #",
   "# # ###### ###### # #",
   "# # # #     #   # # #",
   "# # # # ##### # # # #",
   "# # # #    #  # # # #",
   "# # # # ## ## # # # #",
   "# ### ###   # # # # #",
   "# #   #   #   #   # #",
   "# # # # #   ### ### #",
   "# # # # ## ## # # # #",
   "# # # #  #    # # # #",
   "# # # # ##### # # # #",
   "# # #   #     # # # #",
   "# # ###### ###### # #",
   "# #      #        # #",
   "# # ############# # #",
   "#   #             # #",
   "#####################",
   0
   };


void ausgabe()
   {
   int zeile;

   for( zeile = 0; labyrinth[zeile][0] != 0; zeile++ )
      printf( "%s\n", labyrinth[zeile] );
   }

int weg( int start_z, int start_s, int ziel_z, int ziel_s )
   {
   if( ( start_z == ziel_z ) && ( start_s == ziel_s ) )
      {
      labyrinth[start_z][start_s] = '+';
      return 1;
      }
   if( labyrinth[start_z - 1][start_s] == ' ' )
      {
      labyrinth[start_z][start_s] = '^';
      if( weg( start_z - 1, start_s, ziel_z, ziel_s ) )
         return 1;
      }
   if( labyrinth[start_z + 1][start_s] == ' ' )
      {
      labyrinth[start_z][start_s] = 'v';
      if( weg( start_z + 1, start_s, ziel_z, ziel_s ) )
         return 1;
      }
   if( labyrinth[start_z][start_s - 1] == ' ' )
      {
      labyrinth[start_z][start_s] = '<';
      if( weg( start_z, start_s - 1, ziel_z, ziel_s ) )
         return 1;
      }
   if( labyrinth[start_z][start_s + 1] == ' ' )
      {
      labyrinth[start_z][start_s] = '>';
      if( weg( start_z, start_s + 1, ziel_z, ziel_s ) )
         return 1;
      }
   labyrinth[start_z][start_s] = '-';
   return 0;
   }

void main()
   {
   int start_z, start_s, ziel_z, ziel_s;

   ausgabe();

   printf( "\nStart (Zeile Spalte): " );
   scanf( "%d %d", &start_z, &start_s );
   printf( "Ziel (Zeile Spalte): " );
   scanf( "%d %d", &ziel_z, &ziel_s );

   if( weg( start_z, start_s, ziel_z, ziel_s ) )
      ausgabe();
   else
      printf( "Kein Weg gefunden!\n" );

   }
