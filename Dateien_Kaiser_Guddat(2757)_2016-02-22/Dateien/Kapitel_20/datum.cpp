#include <iostream>
#include <cstdlib>
using namespace std;

#include "datum.h"



ostream& operator<<( ostream& os, const datum& dat )
   {
   switch( dat.modus )
      {
      case 0:
         os << dat.tag << '.' << dat.mon << '.' << dat.jahr;
         break;
      case 1:
         os << dat.tag << '.';
         switch( dat.mon )
            {
            case( 1 ) :
               os << " Jan. " << dat.jahr;
               break;
            case( 2 ) :
               os << " Feb. " << dat.jahr;
               break;
            case( 3 ) :
               os << " Mrz. " << dat.jahr;
               break;
            case( 4 ) :
               os << " Apr. " << dat.jahr;
               break;
            case( 5 ) :
               os << " Mai " << dat.jahr;
               break;
            case( 6 ) :
               os << " Jun. " << dat.jahr;
               break;
            case( 7 ) :
               os << " Jul. " << dat.jahr;
               break;
            case( 8 ) :
               os << " Aug. " << dat.jahr;
               break;
            case( 9 ) :
               os << " Sep. " << dat.jahr;
               break;
            case( 10 ) :
               os << " Okt. " << dat.jahr;
               break;
            case( 11 ) :
               os << " Nov. " << dat.jahr;
               break;
            case( 12 ) :
               os << " Dez. " << dat.jahr;
               break;
            default:
               os << " unbekannter Monat " << dat.jahr;;
            }
         break;
      case 2:
         os << dat.tag << '.';
         switch( dat.mon )
            {
            case( 1 ) :
               os << " Januar " << dat.jahr;
               break;
            case( 2 ) :
               os << " Februar " << dat.jahr;
               break;
            case( 3 ) :
               os << " Maerz " << dat.jahr;
               break;
            case( 4 ) :
               os << " April " << dat.jahr;
               break;
            case( 5 ) :
               os << " Mai " << dat.jahr;
               break;
            case( 6 ) :
               os << " Juni " << dat.jahr;
               break;
            case( 7 ) :
               os << " Juli " << dat.jahr;
               break;
            case( 8 ) :
               os << " August " << dat.jahr;
               break;
            case( 9 ) :
               os << " September " << dat.jahr;
               break;
            case( 10 ) :
               os << " Oktober " << dat.jahr;
               break;
            case( 11 ) :
               os << " November " << dat.jahr;
               break;
            case( 12 ) :
               os << " Dezember " << dat.jahr;
               break;
            default:
               os << " unbekannter Monat " << dat.jahr;
            }
         break;
      default:
         os << "Modus unbekannt!";
      }
   return os;
   }

int datum::schaltjahr( int j )
   {
   int schaltjahr;

   if( j % 4 != 0 )
      schaltjahr = 0;
   else
   if( j % 100 != 0 )
      schaltjahr = 1;
   else
   if( j % 400 == 0 )
      schaltjahr = 1;
   else
      schaltjahr = 0;

   return schaltjahr;
   }

int datum::datumOk( int tag, int mon, int jahr )
   {
   if( jahr <= 1900 )
      return 0;

   if( mon <= 0 || mon >= 13 )
      return 0;

   if( tag <= 0 )
      return 0;

   switch( mon )
      {
      case 4:
      case 6:
      case 9:
      case 11:
         if( tag > 30 )
            return 0;
         break;
      case 2:
         if( tag > ( schaltjahr( jahr ) ? 29 : 28 ) )
            return 0;
         break;
      default:
         if( tag > 31 )
            return 0;
      }
   return 1;
   }

unsigned int datum::tageDesMonats( int mon, int jahr )
   {
   switch( mon )
      {
      case 4:
      case 6:
      case 9:
      case 11:
         return 30;
         break;
      case 2:
         if( schaltjahr( jahr ) )
            return 29;
         return 28;
         break;
      default:
         return 31;
      }
   }

unsigned int datum::dat2Tage()
   {
   unsigned int anz = 0;
   int i;
   int j;

   j = jahr - 1900;
   anz = j * 365 + j / 4 - j / 100 + j / 400 + 1;

   for( i = 1; i < mon; i++ )
      anz += tageDesMonats( i, jahr );

   anz += tag;
   return anz;
   }

void datum::tage2Dat( unsigned long int tage )
   {
   jahr = 1900;
   while( tage >( unsigned )365 + schaltjahr( jahr ) )
      {
      tage = tage - ( 365 + schaltjahr( jahr ) );
      jahr++;
      }

   mon = 1;
   while( tage > tageDesMonats( mon, jahr ) )
      {
      tage = tage - tageDesMonats( mon, jahr );
      mon++;
      }

   tag = tage;
   }



datum::datum()
   {
   tag = 1;
   mon = 1;
   jahr = 1900;
   modus = 0;
   }

datum::datum( int t, int m, int j )
   {
   if( datumOk( t, m, j ) )
      {
      tag = t;
      mon = m;
      jahr = j;
      modus = 0;
      }
   else
      {
      tag = 1;
      mon = 1;
      jahr = 1900;
      modus = 0;
      }
   }

datum::datum( int t, int m, int j, int mod )
   {
   if( datumOk( t, m, j ) )
      {
      tag = t;
      mon = m;
      jahr = j;
      modus = mod;
      }
   else
      {
      tag = 1;
      mon = 1;
      jahr = 1900;
      modus = 0;
      }
   }


void datum::setDatum( int t, int m, int j )
   {
   if( datumOk( t, m, j ) )
      {
      tag = t;
      mon = m;
      jahr = j;
      }
   }

void datum::setDatum( datum& neu )
   {
   if( datumOk( neu.tag, neu.mon, neu.jahr ) )
      {
      tag = neu.tag;
      mon = neu.mon;
      jahr = neu.jahr;
      }
   }

void datum::setModus( int mod )
   {
   if( mod >= 0 && mod <= 2 )
      modus = mod;
   }

datum datum::operator+( int t )
   {
   datum temp;
   unsigned int tage;

   tage = dat2Tage() + t;
   temp.tage2Dat( tage );

   temp.setModus( modus );
   return temp;
   }

int datum::operator-( datum& dat )
   {
   int tage;

   tage = dat2Tage();
   tage -= dat.dat2Tage();

   return tage;
   }

int datum::operator==( datum& dat )
   {
   if( dat2Tage() == dat.dat2Tage() )
      return 1;
   else
      return 0;
   }

int datum::operator>( datum& dat )
   {
   if( dat2Tage() > dat.dat2Tage() )
      return 1;
   else
      return 0;
   }

int datum::operator<( datum& dat )
   {
   if( dat2Tage() < dat.dat2Tage() )
      return 1;
   else
      return 0;
   }

int datum::wochentag()
   {
   return ( ( dat2Tage() - 1 ) % 7 );
   }

int datum::feiertag()
   {
   if( ( tag == 1 && mon == 1 ) //Neujahr
       || ( tag == 1 && mon == 5 ) //Maifeiertag
       || ( tag == 9 && mon == 5 ) //Chriti Himmelfahrt
       || ( tag == 3 && mon == 10 ) //Tag der Einheit
       || ( tag == 1 && mon == 11 ) //Allerheiligen
       || ( tag == 25 && mon == 12 ) //1. Weihnachtstag
       || ( tag == 26 && mon == 12 ) )//2. Weihnachtstag
       return 1;
   return 0;
   }
