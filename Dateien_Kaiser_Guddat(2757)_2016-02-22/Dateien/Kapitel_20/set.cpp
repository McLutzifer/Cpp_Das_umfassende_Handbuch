# include "set.h"

/*
** Menge Implementierung (Kap. 20.9.1)
*/
set::set() {
   int i;
   for( i = 0; i < 32; i++ )
      data[i] = 0;
   }

set& operator+= ( set& s1, const set& s2 )
   {
   int i;
   for( i = 0; i < 32; i++ )
      s1.data[i] |= s2.data[i];
   return s1;
   }

set operator+ ( const set& s1, const set& s2 )
   {
   set r;
   r = s1;
   r += s2;
   return r;
   }

set& operator-= ( set& s1, const set& s2 )
   {
   int i;
   for( i = 0; i < 32; i++ )
      s1.data[i] &= ~s2.data[i];
   return s1;
   }

set operator- ( const set& s1, const set& s2 )
   {
   set r;
   r = s1;
   r -= s2;
   return r;
   }

set& operator*= ( set& s1, const set& s2 )
   {
   int i;
   for( i = 0; i < 32; i++ )
      s1.data[i] &= s2.data[i];
   return s1;

   }
set operator* ( const set& s1, const set& s2 )
   {
   set r;
   r = s1;
   r *= s2;
   return r;
   }

set operator~ ( const set& s )
   {
   int i;
   set r;
   for( i = 0; i < 32; i++ )
      r.data[i] = ~s.data[i];
   return r;
   }
set& operator+= ( set& s1, const int e )
   {
   if( ( e >= 0 ) && ( e < 256 ) ) s1.data[e / 8] |= ( 1 << ( e % 8 ) );
   return s1;
   }

set operator+ ( const set& s1, const int e )
   {
   set r;
   r = s1;
   r += e;
   return r;
   }

set& operator-= ( set& s1, const int e )
   {
   if( ( e >= 0 ) && ( e < 256 ) ) s1.data[e / 8] &= ~( 1 << ( e % 8 ) );
   return s1;
   }
set operator- ( const set& s1, const int e )
   {
   set r;
   r = s1;
   r -= e;
   return r;
   }

int operator<= ( const set& s1, const set& s2 )
   {
   int i; for( i = 0; i < 32; i++ )
      {
      if( ( s1.data[i] & s2.data[i] ) != s1.data[i] )
         return 0;
      }
   return 1;
   }

int operator<( int e, const set& s )
   {
   if( ( e >= 0 ) && ( e < 256 ) )
      return s.data[e / 8] & ( 1 << ( e % 8 ) );
   return 0;
   }

int operator! ( const set& s )
   {
   int i;
   for( i = 0; i < 32; i++ )
      {
      if( s.data[i] )
         return 0;
      }
   return 1;
   }

ostream& operator<< ( ostream& os, const set& s )   {
   int i;
   int append;
   os << '{';
   for( i = 0, append = 0; i < 256; i++ )
      {
      if( i < s )
         {
         if( append )
            os << ',';
         append = 1;
         os << ' ' << i;
         }
      }
   os << '}' << '\n';
   return os;
   }