# include "string_klasse.h"
# include <cstring>
# include <cstdlib>
using namespace std;


string::string( char *txt )
{
   alen = strlen( txt ) + 1;
   len = alen;
   text = ( char * ) malloc( alen * sizeof( char ) );
   strcpy( text, txt );
}

string::string( const string &s )
{
   alen = s.len;
   len = s.len;
   text = ( char * ) malloc( ( s.len + 1 ) * sizeof( char ) );
   strcpy( text, s.text );
}

string::~string()
{
   if ( text )
      free( text );
}

void string::set_text( char *buf )
{
   int zusatz;

   zusatz = strlen( buf ) + 1;

   if ( alen - zusatz <= 0 )
   {
      text = ( char * ) realloc( text, zusatz * sizeof( char ) );

      alen = zusatz;
      len = zusatz;
      strcpy( text, buf );
   }
   else
   {
      len = zusatz;
      strcpy( text, buf );
   }
}


string string::operator+( const string &t )
{
   string neu( text );

   if ( ( neu.len + t.len ) >= neu.alen )
   {
      neu.text = ( char * ) realloc( neu.text, ( neu.len + t.len + 1 ) * sizeof( char ) );

      strcat( neu.text, t.text );
      neu.len += t.len;
      neu.alen = neu.len + t.len;
   }
   else
   {
      strcat( neu.text, t.text );
      neu.len += t.len;
   }
   return neu;
}

string string::operator=( const string &t )
{
   if ( t.len > alen )
   {
      text = ( char * ) realloc( text, ( t.len + 1 ) * sizeof( char ) );

      strcpy( text, t.text );
      len = t.len;
      alen = t.len;
   }
   else
   {
      strcpy( text, t.text );
      len = t.len;
   }

   return *this;
}

int string::search_for( const string *t )
{
   int i;
   int a;

   for ( i = 0; text[i]; i++ )
   {
      for ( a = 0; t->text[a]; a++ )
      {
         if ( text[a + i] != t->text[a] )
            break;
         return 1;
      }
   }
   return 0;
}


int string::compare_cs( string *t )
{
   return ( strcmp( text, t->text ) );
}


void string::insert( string *t, int pos )
{
   char *buffer = ( char* ) calloc( ( len + t->len ), sizeof( char ) );

   strcpy( buffer, text + pos );

   if ( alen <= len + t->len )
   {
      text = ( char * ) realloc( text, ( alen + t->alen ) * sizeof( char ) );
      alen += t->alen;
   }

   strcpy( text + pos, t->text );
   strcat( text, buffer );
   len += t->len;

   free( buffer );
}


void string::extract( int from, int to )
{
   strcpy( text, text + from - 1 );
   text[to - from + 1] = 0;
}

void string::set_char( int pos, char c )
{
   if ( ( pos < len ) && ( pos >= 1 ) )
   {
      text[pos - 1] = c;
   }
   else
   {
      printf( "\n Ungueltige Position !\n" );
   }
}


char string::get_char( int pos )
{
   if ( ( pos < len ) && ( pos >= 1 ) )
   {
      return text[pos - 1];
   }
   else
   {
      printf( "\n Ungueltige Position !\n" );
      return 0;
   }
}
