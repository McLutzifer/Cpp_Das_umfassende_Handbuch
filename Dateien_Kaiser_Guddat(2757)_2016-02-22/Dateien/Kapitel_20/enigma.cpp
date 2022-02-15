# include <ostream>
# include <cstdlib>
# include <cstring>

using namespace std;

# include "enigma.h"

//********************************************
//Implementierung des Steckbretts
//********************************************

steckbrett::steckbrett( int *steck )
   {
   int i;

   for( i = 0; i < 26; i++ )
      {
      if( steck[i] >= 0 && steck[i] <= 25 )
         s[i] = steck[i];
      else
         s[i] = 0;
      }
   }

inline int steckbrett::hin( int links )
   {
   return s[links];
   }

inline int steckbrett::zur( int rechts )
   {
   int i;

   for( i = 0; i < 26; i++ )
   if( s[i] == rechts )
      return i;
   return 0;
   }

//Ende der Implementierung des Steckbretts
//********************************************


//********************************************
//Implementierung der Rotoren
rotor::rotor( int *rr, rotor *n, int r_a )
   {
   int i;

   for( i = 0; i < 26; i++ )
      r[i] = rr[i];

   if( r_a >= 0 && r_a <= 25 )
      r_akt = r_a;
   else
      r_akt = 0;

   next = n;
   }

void rotor::set_pos( int r_a )
   {
   if( r_a >= 0 && r_a <= 25 )
      r_akt = r_a;
   }

inline int rotor::hin( int links )
   {
   return r[links];
   }

inline int rotor::zur( int rechts )
   {
   int i;

   for( i = 0; i < 26; i++ )
   if( r[i] == rechts )
      return i;
   return 0;
   }

inline int rotor::diff( int val )
   {
   int j, k;

   for( k = 0, j = r_akt; ( j %= 26 ) != val; j++ )
      k++;
   return k;
   }

void rotor::mov()
   {
   if( ++r_akt > 25 )
      {
      r_akt = 0;
      if( next )
         next->mov();
      }
   }

//Ende der Implementierung der Rotoren
//********************************************

//********************************************
//Implementierung des Reflektors
reflektor::reflektor( int *ref )
   {
   int i;

   for( i = 0; i < 26; i++ )
      {
      if( ref[i] >= 0 && ref[i] <= 25 )
         r[i] = ref[i];
      else
         r[i] = 0;
      }
   }

inline int reflektor::hin( int links )
   {
   return r[links];
   }

//Ende der Implemetierung des Reflektors
//********************************************

//********************************************
//Implementierung der Enigma

//Nur für Testausgaben
/*
ostream& operator<<(ostream& os, enigma& e)
{
int i;
int r1_a = e.r1->r_akt;
int r2_a = e.r2->r_akt;
int r3_a = e.r3->r_akt;

os << "Steck R1   R2   R3  Refl\n";
for(i = 0; i < 26; i++)
{
os << i << ":" << e.steckb->s[i] << "  ";
os << r1_a << ":" << e.r1->r[r1_a] << "  ";
os << r2_a << ":" << e.r2->r[r2_a] << "  ";
os << r3_a << ":" << e.r3->r[r3_a] << "  ";
os << i << ":" << e.refl->r[i] << '\n';

if(++r1_a > 25) r1_a = 0;
if(++r2_a > 25) r2_a = 0;
if(++r3_a > 25) r3_a = 0;
}
return os;
}
*/
enigma::enigma( int *steck,
                int *r_1, int *r_2, int *r_3,
                int r1_a, int r2_a, int r3_a,
                int *ref )
   {
   steckb = new steckbrett( steck );

   r3 = new rotor( r_3, 0, r3_a );
   r2 = new rotor( r_2, r3, r2_a );
   r1 = new rotor( r_1, r2, r1_a );

   refl = new reflektor( ref );

   text = 0;
   }

enigma::~enigma()
   {
   if( text )
      free( text );

   delete steckb;
   delete r1;
   delete r2;
   delete r3;
   delete refl;
   }

char* enigma::work( char *c )
   {
   unsigned int i;
   int s_pos, r1_pos, r2_pos, r3_pos, ref_pos;

   if( !text )
      text = ( char* ) calloc( strlen( c ) + 1, sizeof( char ) );
   else
   if( strlen( c ) > strlen( text ) )
      text = ( char* ) realloc( text, ( strlen( c ) + 1 )*sizeof( char ) );

   for( i = 0; i < strlen( c ); i++ )
      {
      if( c[i] == ' ' )
         {
         text[i] = ' ';
         continue;
         }

      text[i] = 0;

      s_pos = c[i] - 'A';
      text[i] = text[i] - s_pos + steckb->hin( s_pos );

      r1_pos = ( r1->akt() + steckb->hin( s_pos ) ) % 26;
      text[i] = text[i] - r1_pos + r1->hin( r1_pos );

      r2_pos = ( r2->akt() + r1->diff( r1->hin( r1_pos ) ) ) % 26;
      text[i] = text[i] - r2_pos + r2->hin( r2_pos );

      r3_pos = ( r3->akt() + r2->diff( r2->hin( r2_pos ) ) ) % 26;
      text[i] = text[i] - r3_pos + r3->hin( r3_pos );

      ref_pos = r3->diff( r3->hin( r3_pos ) ) % 26;
      text[i] = text[i] - ref_pos + refl->hin( ref_pos );

      r3_pos = ( r3->akt() + refl->hin( ref_pos ) ) % 26;
      text[i] = text[i] - r3_pos + r3->zur( r3_pos );

      r2_pos = ( r2->akt() + r3->diff( r3->zur( r3_pos ) ) ) % 26;
      text[i] = text[i] - r2_pos + r2->zur( r2_pos );

      r1_pos = ( r1->akt() + r2->diff( r2->zur( r2_pos ) ) ) % 26;
      text[i] = text[i] - r1_pos + r1->zur( r1_pos );

      s_pos = r1->diff( r1->zur( r1_pos ) ) % 26;
      text[i] = text[i] - s_pos + steckb->zur( s_pos );

      text[i] = ( c[i] + ( text[i] % 26 ) );
      if( text[i] < 'A' )
         text[i] = text[i] + ( 'Z' - 'A' + 1 );
      if( text[i] > 'Z' )
         text[i] = text[i] - ( 'Z' - 'A' + 1 );

      r1->mov();
      }
   text[i] = 0;
   return text;
   }

//Ende der Implementierung der Enigma
//********************************************