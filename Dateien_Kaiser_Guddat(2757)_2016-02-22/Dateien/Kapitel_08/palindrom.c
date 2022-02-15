int palindrom( char *string )
   {
   char *vorn   = string;
   char *hinten = string;

   for ( ; *hinten != 0; hinten++)
      ;
   hinten--;
   for ( ; vorn < hinten; vorn++, hinten--)
      {
      if (*vorn != *hinten)
         return 0;
      }
   return 1;
   }


void main()
   {
   int ok;

   ok = palindrom( "retsinakanister" );
   if (ok == 1)
      printf( "Palindrom erkannt\n" );
   }
