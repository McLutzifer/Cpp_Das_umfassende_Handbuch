# include <stdio.h>
# include <stdlib.h>


void main()
   {
   int jahr;

   printf( "Jahr: " );
   scanf( "%d", &jahr );

   if( jahr % 400 == 0 )
      printf( "%d ist ein Schaltjahr\n", jahr );
   else
      {
      if( jahr % 100 == 0 )
         printf( "%d ist kein Schaltjahr\n", jahr );
      else
         {
         if( jahr % 4 == 0 )
            printf( "%d ist ein Schaltjahr\n", jahr );
         else
            printf( "%d ist kein Schaltjahr\n", jahr );
         }
      }
   }
