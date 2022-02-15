# include <string.h>

void main()
   {
   char eingabe[100];
   char text[500];

   for (text[0] = 0; ; )
      {
      printf( "Eingabe: " );
      scanf( "%s", eingabe );
      if (strcmp( eingabe, "ende" ) == 0)
         break;

      if (strlen( text ) + strlen( eingabe ) < 500)
         strcat( text, eingabe );
      }
   printf( "%s\n", text );
   }
