#ifndef __STRING_KLASSE_H__
#define __STRING_KLASSE_H__

# include <cstdio>
# include <cstdlib>
using namespace std;

class string
{
   private:

      int len;
      int alen;
      char *text;

   public:

      string( char *txt );
      string( const string &s );
      ~string();

      int get_len() { return len; }
      char *get_text() { return text; }
      void set_text( char *buf );

      string operator+( const string &t );
      string operator=( const string &t );

      int search_for( const string *t );
      int compare_cs( string *t );
      void insert( string *t, int pos );
      void extract( int from, int to );
      void set_char( int pos, char c );
      char get_char( int pos );
};

#endif
