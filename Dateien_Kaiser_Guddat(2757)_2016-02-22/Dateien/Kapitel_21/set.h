# ifndef SET_H
# define SET_H

/*
** Menge Headerdatei (Kap. 20.9.1)
*/

# include <iostream>

using namespace std;



class set
   {
   friend set operator+( const set& s1, const set& s2 );
   friend set operator-( const set& s1, const set& s2 );
   friend set operator*( const set& s1, const set& s2 );
   friend set operator~( const set& s );
   friend set operator+( const set& s, const int e );
   friend set operator-( const set& s, const int e );

   friend set& operator+=( set& s1, const set& s2 );
   friend set& operator-=( set& s1, const set& s2 );
   friend set& operator*=( set& s1, const set& s2 );
   friend set& operator+=( set& s, const int e );
   friend set& operator-=( set& s, const int e );

   friend int operator<= ( const set& s1, const set& s2 );
   friend int operator< ( int e, const set& s2 );
   friend int operator! ( const set& s );

   friend ostream& operator<< ( ostream& os, const set& s );
   private:
      unsigned char data[32];
   public:
      set();
   };

# endif