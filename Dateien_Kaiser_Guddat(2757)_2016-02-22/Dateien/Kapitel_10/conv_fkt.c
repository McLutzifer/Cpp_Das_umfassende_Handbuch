# include <ctype.h>

void main()
   {
   char text[100];
   int  u, l;
   char *p;

   printf( "Eingabe: " );
   scanf( "%s", text );
   for (p = text, u = l = 0; *p; p++)
      {
      if (isupper( *p ))
         u++;
      if (islower( *p ))
         l++;
      }
   printf( "%d Gross-, %d Kleinbuchstaben\n", u, l );

   for (p = text; *p; p++)
      *p = toupper( *p );
   printf( "Gross:   %s\n", text );
   for (p = text; *p; p++)
      *p = tolower( *p );
   printf( "Klein:   %s\n", text );
   }
