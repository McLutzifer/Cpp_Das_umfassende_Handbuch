# include <stdio.h>
# include <stdlib.h>

/*
** Schaltung (Kap. 5.6.2)
*/

void main()
   {
   int s1, s2, s3, s4, s5, s6, s7;
   int lampe;

   printf( "  s1 s2 s3 s4 s5 s6 s7\n" );
   for( s1 = 0; s1 <= 1; s1 = s1 + 1 )
      {
      for( s2 = 0; s2 <= 1; s2 = s2 + 1 )
         {
         for( s3 = 0; s3 <= 1; s3 = s3 + 1 )
            {
            for( s4 = 0; s4 <= 1; s4 = s4 + 1 )
               {
               for( s5 = 0; s5 <= 1; s5 = s5 + 1 )
                  {
                  for( s6 = 0; s6 <= 1; s6 = s6 + 1 )
                     {
                     for( s7 = 0; s7 <= 1; s7 = s7 + 1 )
                        {
                        lampe = ( s1 || s2 ) && ( ( s3&&s4 ) || ( ( s5 || s6 ) && s7 ) );
                        if( lampe == 1 )
                           printf( "   %d  %d  %d  %d  %d  %d  %d\n",
                           s1, s2, s3, s4, s5, s6, s7 );
                        }
                     }
                  }
               }
            }
         }
      }
   }

