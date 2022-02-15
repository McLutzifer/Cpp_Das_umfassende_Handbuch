# include <stdio.h>
# include <stdlib.h>


void main()
   {
   int tag, monat, jahr;
   int schalttag;
   int laufender_tag;

   printf( "Tag: " );
   scanf( "%d", &tag );
   printf( "Monat: " );
   scanf( "%d", &monat );
   printf( "Jahr: " );
   scanf( "%d", &jahr );

   if( jahr % 400 == 0 )
      schalttag = 1;
   else
      {
      if( jahr % 100 == 0 )
         schalttag = 0;
      else
         {
         if( jahr % 4 == 0 )
            schalttag = 1;
         else
            schalttag = 0;
         }
      }
   laufender_tag = tag;
   if( monat > 1 )
      laufender_tag += 31;
   if( monat > 2 )
      laufender_tag += 28 + schalttag;
   if( monat > 3 )
      laufender_tag += 31;
   if( monat > 4 )
      laufender_tag += 30;
   if( monat > 5 )
      laufender_tag += 31;
   if( monat > 6 )
      laufender_tag += 30;
   if( monat > 7 )
      laufender_tag += 31;
   if( monat > 8 )
      laufender_tag += 31;
   if( monat > 9 )
      laufender_tag += 30;
   if( monat > 10 )
      laufender_tag += 31;
   if( monat > 11 )
      laufender_tag += 30;
   printf( "Der %d.%d.%d ist der %d. Tag des Jahres\n", tag, monat, jahr, laufender_tag );
   }
