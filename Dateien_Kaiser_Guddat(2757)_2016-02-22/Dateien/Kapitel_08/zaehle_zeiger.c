int zaehle( char string[] )
   {
   int i, a;

   for (i = 0, a = 0; string[i] != 0; i++)
      {
      if (string[i] == 'a')
         a++;
      }
   return a;
   }


void main()
   {
   int anz;

   anz = zaehle( "Panamakanalaal" );
   printf( "%d a gefunden\n", anz );
   }
