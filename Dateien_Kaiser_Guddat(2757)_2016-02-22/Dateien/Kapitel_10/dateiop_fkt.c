# include <stdio.h>
# include <stdlib.h>

void main()
   {
   char token[100];
   int  counter = 0;
   FILE *pf;

   pf = fopen( "dateiop_fkt.c", "r" );
   if (pf == 0)
      return;

   for ( ; ; )
      {
      fscanf( pf, "%s", token );
      if (feof( pf ))
         break;
      counter++;
      printf( "Token %3d: %s \n", counter, token );
      }
   fclose( pf );
   }
