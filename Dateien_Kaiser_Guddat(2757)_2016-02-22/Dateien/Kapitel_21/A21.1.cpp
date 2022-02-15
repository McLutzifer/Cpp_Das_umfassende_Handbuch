# include <cstdio>
# include <cstdlib>
# include "string_klasse.h"

using namespace std;
# define MAXSTRING 10

int main()
{
   string *strng[MAXSTRING];
   char befehl;
   int number1;
   int number2;
   int pos;
   int to;
   char buchst;
   char buf[200];
   int i;

   for ( i = 0; i < MAXSTRING; i++ )
   {
      strng[i] = 0;
   }

   for ( i = 0;; i++ )
   {
      if ( !( i % 10 ) )
      {
         printf( "\n  w nr text         -> write text to string nr[0-9]\n" );
         printf( "  s nr              -> show string with nr[0-9]\n" );
         printf( "  a nr1 nr2         -> add to string nr1 [0-9] string nr2 [0-9]\n" );
         printf( "  g nr1 nr2         -> search for string nr2 in string nr1\n" );
         printf( "  c nr1 nr2         -> compare strings case sensitive\n" );
         printf( "  e nr1 nr2 pos     -> insert string nr2 into string nr1 at position pos\n" );
         printf( "  r nr1 from to     -> extract part of string nr1 (from...to)\n" );
         printf( "  t nr pos char     -> put char in string nr at position pos\n" );
         printf( "  h nr pos          -> get char at pos from string nr\n" );
         printf( "  q                 -> quit program\n\n" );
      }

      fflush( stdin );
      printf( " Command: " );
      scanf( "%c", &befehl );

      if ( befehl == 'q' )
      {
         for ( i = 0; i < MAXSTRING; i++ )
         {
            if ( strng[i] != 0 )
            {
               delete strng[i];
            }
         }
         printf( "\n\t PROGRAMMENDE\n\n" );
         break;
      }

      switch ( befehl )
      {
      case ( 's' ) :
      {
         scanf( "%d", &number1 );
         printf( "\n Der Text: %s\n\n", strng[number1]->get_text() );
         break;
      }
      case ( 'w' ) :
      {
         scanf( "%d", &number1 );
         scanf( "%s", buf );

         strng[number1] = new string( buf );
         break;
      }
      case ( 'a' ) :
      {
         scanf( "%d", &number1 );
         scanf( "%d", &number2 );

         *( strng[number1] ) = *( strng[number1] ) + *( strng[number2] );
         break;
      }
      case ( 'g' ) :
      {
         scanf( "%d", &number1 );
         scanf( "%d", &number2 );

         if ( strng[number1]->search_for( strng[number2] ) )
         {
            printf( "\n STRING GEFUNDEN !\n\n" );
            break;
         }
         else
         {
            printf( "\n STRING NICHT GEFUNDEN !\n\n" );
            break;
         }
         break;
      }
      case ( 'c' ) :
      {
         scanf( "%d", &number1 );
         scanf( "%d", &number2 );

         if ( !strng[number1]->compare_cs( strng[number2] ) )
         {
            printf( "\n STRINGS GLEICH !\n" );
            break;
         }
         printf( "\n STRINGS UNTERSCHIEDLICH !\n" );
         break;
      }
      case ( 'e' ) :
      {
         scanf( "%d", &number1 );
         scanf( "%d", &number2 );
         scanf( "%d", &pos );

         strng[number1]->insert( strng[number2], pos );
         break;
      }
      case ( 'r' ) :
      {
         scanf( "%d", &number1 );
         scanf( "%d", &pos );
         scanf( "%d", &to );

         strng[number1]->extract( pos, to );
         break;
      }
      case ( 't' ) :
      {
         scanf( "%d", &number1 );
         scanf( "%d ", &pos );
         scanf( "%c", &buchst );

         strng[number1]->set_char( pos, buchst );
         break;
      }
      case ( 'h' ) :
      {
         scanf( "%d", &number1 );
         scanf( "%d", &pos );

         buchst = strng[number1]->get_char( pos );

         if ( buchst )
         {
            printf( "\n Gelesener Buchstabe: %c\n", buchst );
            break;
         }
      }
      default:
      {
         printf( "\n Befehl nicht erkannt !\n" );
         break;
      }
      }
      scanf( "%c", &befehl );//Eingefuegt wegen Problemen mit fflush(stdin)
      //Bei anderen Compilern moeglicherweise nicht notwendig
      //z.B. beim Microsoft Compiler
      return 0;
   }
}
