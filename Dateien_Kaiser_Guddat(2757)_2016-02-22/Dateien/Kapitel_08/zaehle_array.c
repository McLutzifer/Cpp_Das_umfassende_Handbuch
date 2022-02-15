int zaehle( char *string)
   {
int a;
   for( a = 0; *string != 0; string++)
      {
      if( *string == 'a')
         a++;
} return a;
}
void main() {
   int anz;
   anz = zaehle( "Panamakanalaal");
   printf( "%d a gefunden\n", anz);
   }
